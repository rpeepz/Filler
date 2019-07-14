/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:33 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/13 21:41:30 by rpapagna         ###   ########.fr       */
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

static void		piece_blocks(t_game *filler, t_try *list, t_point point, int n)
{
	int		i;

	i = 0;
	list->block = ft_memalloc(sizeof(t_point) * n);
	while (point.y < filler->piece.tall)
	{
		point.x = 0;
		while (point.x < filler->piece.wide)
		{
			if (filler->piece.data[point.y][point.x] == '*')
			{
				list->block[i].x = point.x -
				list->anchor.x;
				list->block[i].y = point.y -
				list->anchor.y;
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

static void		next_nodes(t_try **list, int block_count)
{
	t_try	*new;

	new = ft_memalloc(sizeof(t_try));
	new->score = INT32_MAX;
	new->block_count = block_count;
	new->block = NULL;
	new->next = NULL;
	(*list)->next = new;
	*list = (*list)->next;

}

/*
**	find the diff of how much is covered and add to score
*/

static int		scan_diff(t_game *filler, t_try *cur, int max, int mode)
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
		cur->score = max - tmp;
	}
	return (1);
}

/*
**	make a list of scores based on expanded coverage across
**	the dimension specified by the max[] of the piece given.
**	set and change anchor to next block.
**	update best score for current t_score.
*/

void			do_phase(t_game *filler, t_score *scores, int max, int mode)
{
	int		ret;
	int		block_count;
	int		anc_count;
	t_point	point;
	t_try	*list;

	anc_count = 0;
	point = (t_point){0, 0};
	list = scores->rotation;
	block_count = list->block_count;
	piece_anchor(list, filler->piece, point, 0);
	while (++anc_count < block_count)
	{
		piece_blocks(filler, list, point, block_count);
		ret = scan_diff(filler, list, max, mode);
		list->anchor.x = list->anchor.x + list->block[anc_count].x;
		list->anchor.y = list->anchor.y + list->block[anc_count].y;
		if (list->score < scores->score)
			scores->score = list->score;
		if (ret)
			next_nodes(&list, block_count);
	}
	scores->rotation = sort_trys(scores->rotation);
}
