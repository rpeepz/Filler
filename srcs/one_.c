/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:33 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/12 15:01:35 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	find the diff of how much is covered and add to score
*/

static int		scan_diff(t_game *filler, t_point point, int to_match, int mode)
{
	int		i;
	int		tmp;

	i = -1;
	while (++i < filler->scores->scores->block_count)
	{
		tmp = !mode ?
		filler->scores->board_point.x + filler->scores->scores->block[i].x :
		filler->scores->board_point.y + filler->scores->scores->block[i].y;
		if ((tmp > (!mode ? filler->board.wide : filler->board.tall) || tmp < 0)
			|| ((!mode ? filler->board.data[filler->scores->board_point.y][tmp]
			: filler->board.data[tmp][filler->scores->board_point.x]) ==
			filler->you.id) || (i != 0 && (!mode ?
			filler->board.data[filler->scores->board_point.y][tmp]
			: filler->board.data[tmp][filler->scores->board_point.x]) ==
			filler->me.id))
			return (0);
		tmp = ABS(!mode ? filler->scores->scores->block[i].x :
			filler->scores->scores->block[i].y) + filler->board.max[mode];
		if (to_match - tmp < filler->scores->scores->score)
			filler->scores->scores->score = to_match - tmp;
	}
	return (1);
}

/*
**	find initial state all blocks
*/

static void		piece_blocks(t_game *filler, t_point point, int count, int i)
{
	filler->scores->scores->block = ft_memalloc(sizeof(t_point) * count);
	while (point.y < filler->piece.tall)
	{
		point.x = 0;
		while (point.x < filler->piece.wide)
		{
			if (filler->piece.data[point.y][point.x] == '*')
			{
				filler->scores->scores->block[i].x = point.x -
				filler->scores->scores->anchor.x;
				filler->scores->scores->block[i].y = point.y -
				filler->scores->scores->anchor.y;
				i++;
			}
			point.x++;
		}
		point.y++;
	}
}

/*
**	find initial state of anchor and number of blocks
*/

static void		piece_anchor(t_game *filler, t_point point, int block)
{
	while (point.y < filler->piece.tall)
	{
		point.x = 0;
		while (point.x < filler->piece.wide)
		{
			if (filler->piece.data[point.y][point.x] == '*')
			{
				if (!block)
				{
					filler->scores->scores->anchor = point;
				}
				block++;
			}
			point.x++;
		}
		point.y++;
	}
	filler->scores->scores->block_count = block;
}

/*
**	move to the next position in the list
*/

static void		next_nodes(t_try **list)
{
	t_try	*cur;
	t_try	*new;

	cur = *list;
	cur->next = new;
	new = ft_memalloc(sizeof(t_try));
	new->block = cur->block;
	new->score = cur->score;
	cur = cur->next;
}

/*
**	make a list of scores based on expanded coverage across
**	the dimension specified by the max[] of the piece given
*/

void			get_phase_one(t_game *filler, int to_match, int mode)
{
	int		anc_count;
	int		ret;
	t_point	point;
	t_try	*list;

	anc_count = 0;
	point = (t_point){0, 0};
	list = filler->scores->scores;
	piece_anchor(filler, point, 0);
	piece_blocks(filler, point, filler->scores->scores->block_count, 0);
	while (anc_count < filler->scores->scores->block_count)
	{
//			if ret is 1 then move to next node in list
//			if ret is 0 then skip adding it to the list
		if (scan_diff(filler, point, to_match, mode))
			next_nodes(&filler->scores->scores);
		shift_anchor();
		anc_count++;
	}
	filler->scores->scores = list;
}
