/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:01:33 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/14 21:15:08 by rpapagna         ###   ########.fr       */
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

static t_point	wrapper(t_point point, int wide, int tall)
{
	if (point.x >= wide)
		point.x = point.x - wide;
	if (point.y >= tall)
		point.y = point.y - tall;
	if (point.x < 0)
		point.x = wide + point.x;
	if (point.y < 0)
		point.y = tall + point.y;
	return (point);
}

/*
**	find the diff of how much is covered and add to score
*/

static int		scan_diff(t_game *filler, t_score *scores, int *mo, int anc)
{
	int		i;
	int		point;
	t_point	tmp;

	i = -1;
	while (++i < scores->rotation->block_count)
	{
		tmp.x = scores->board_point.x + scores->rotation->block[i].x;
		tmp.y = scores->board_point.y + scores->rotation->block[i].y;
		if (tmp.x >= filler->board.wide || tmp.y >= filler->board.tall
			|| tmp.x < 0 || tmp.y < 0)
			tmp = wrapper(tmp, filler->board.wide, filler->board.tall);
		if (filler->board.data[tmp.y][tmp.x] == filler->you.id || (i != anc &&
			filler->board.data[tmp.y][tmp.x] == filler->me.id))
			return (0);
		!mo[1] ?
		(point = ABS(scores->rotation->block[i].x) + filler->board.max[mo[1]]) :
		(point = ABS(scores->rotation->block[i].y) + filler->board.max[mo[1]]);
		if (mo[0] - point < mo[2])
			mo[2] = mo[0] - point;
	}
	return (1);
}

/*
**	make a list of scores based on expanded coverage across
**	the dimension specified by the max[] of the piece given.
**	set and change anchor to next block.
**	update best score for current t_score.
*/

void			do_phase(t_game *filler, t_score *scores, int *mo)
{
	int		anc_count;
	t_point	point;

	anc_count = 0;
	point = (t_point){0, 0};
	piece_anchor(scores->rotation, filler->piece, point, 0);
	while (++anc_count < scores->rotation->block_count)
	{
		piece_blocks(filler, scores->rotation, point,
						scores->rotation->block_count);
		if (scan_diff(filler, scores, mo, anc_count - 1))
			if (mo[2] < scores->score)
			{
				scores->score = mo[2];
				scores->rotation->target.x = scores->board_point.x -
				scores->rotation->anchor.x;
				scores->rotation->target.y = scores->board_point.y -
				scores->rotation->anchor.y;
			}
		scores->rotation->anchor.x = scores->rotation->anchor.x +
		scores->rotation->block[anc_count].x;
		scores->rotation->anchor.y = scores->rotation->anchor.y +
		scores->rotation->block[anc_count].y;
	}
}
