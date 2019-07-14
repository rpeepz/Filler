/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:33 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/13 18:28:08 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	find initial state of anchor and number of blocks
*/

static void		piece_anchor(t_try *list, t_token piece, t_point point, int b)
{
	while (point.y < piece.tall)
	{
		point.x = 0;
		while (point.x < piece.wide)
		{
			if (piece.data[point.y][point.x] == '*')
			{
				if (!b)
					list->anchor = point;
				b++;
			}
			point.x++;
		}
		point.y++;
	}
	list->block_count = b;
}

/*
**	find state all blocks in relation to anchor
*/

static void		piece_blocks(t_game *filler, t_point point, int count, int i)
{
	filler->scores->rotation->block = ft_memalloc(sizeof(t_point) * count);
	while (point.y < filler->piece.tall)
	{
		point.x = 0;
		while (point.x < filler->piece.wide)
		{
			if (filler->piece.data[point.y][point.x] == '*')
			{
				filler->scores->rotation->block[i].x = point.x -
				filler->scores->rotation->anchor.x;
				filler->scores->rotation->block[i].y = point.y -
				filler->scores->rotation->anchor.y;
				i++;
			}
			point.x++;
		}
		point.y++;
	}
}

/*
**	move to the next position in the list
*/

static void		next_nodes(t_try **list)
{
	t_try	*cur;
	t_try	*new;

	cur = *list;
	new = ft_memalloc(sizeof(t_try));
	cur->next = new;
	new->score = cur->score;
	new->block_count = cur->block_count;
	new->block = cur->block;
	new->next = NULL;
	cur = cur->next;
}

/*
**	find the diff of how much is covered and add to score
*/

static int		scan_diff(t_game *filler, int to_match, int mode)
{
	int		i;
	int		tmp;

	i = -1;
	while (++i < filler->scores->rotation->block_count)
	{
		tmp = !mode ?
		filler->scores->board_point.x + filler->scores->rotation->block[i].x :
		filler->scores->board_point.y + filler->scores->rotation->block[i].y;
		if ((tmp > (!mode ? filler->board.wide : filler->board.tall) || tmp < 0)
			|| ((!mode ? filler->board.data[filler->scores->board_point.y][tmp]
			: filler->board.data[tmp][filler->scores->board_point.x]) ==
			filler->you.id) || (i != 0 && (!mode ?
			filler->board.data[filler->scores->board_point.y][tmp]
			: filler->board.data[tmp][filler->scores->board_point.x]) ==
			filler->me.id))
			return (0);
		tmp = ABS(!mode ? filler->scores->rotation->block[i].x :
			filler->scores->rotation->block[i].y) + filler->board.max[mode];
		if (to_match - tmp < filler->scores->rotation->score)
			filler->scores->rotation->score = to_match - tmp;
	}
	return (1);
}

/*
**	make a list of scores based on expanded coverage across
**	the dimension specified by the max[] of the piece given.
**	set and change anchor to next block.
**	update best score for current t_score.
*/

void			get_phase_one(t_game *filler, int to_match, int mode)
{
	int		anc_count;
	t_point	point;
	t_try	*list;

	anc_count = 0;
	point = (t_point){0, 0};
	list = filler->scores->rotation;
	piece_anchor(list, filler->piece, point, 0);
	while (++anc_count < list->block_count)
	{
		piece_blocks(filler, point, list->block_count, 0);
		if (scan_diff(filler, to_match, mode))
			next_nodes(&list);
		filler->scores->rotation->anchor.x =
			filler->scores->rotation->anchor.x + list->block[anc_count].x;
		filler->scores->rotation->anchor.y =
			filler->scores->rotation->anchor.y + list->block[anc_count].y;
		if (filler->scores->rotation->score < filler->scores->score)
			filler->scores->score = filler->scores->rotation->score;
	}
}
