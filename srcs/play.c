/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/13 21:41:39 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
/*
int				overlap(t_game filler, t_point spot, t_point to_place, int i)
{
	if (spot.y + to_place.y > filler.board.tall ||
		spot.x + to_place.x > filler.board.wide ||
		spot.y + to_place.y < 0 || spot.x + to_place.x < 0 ||
		filler.board.data[spot.y + to_place.y][spot.x + to_place.x] ==
		filler.you.id)
		return (-1);
	else if (filler.board.data[spot.y + to_place.y][spot.x + to_place.x] ==
		filler.me.id)
		return (i + 1);
	else
		return (0);
}

int				diff_blocks(t_game game, int blocks, int i)
{
	int		block;
	int		count;
	t_point	piece_piece;
	t_point best_spot;

	best_spot.y = game.me_blocks[i].y;
	best_spot.x = game.me_blocks[i].x;
	count = 0;
	block = 0;
	while (block < blocks)
	{
		piece_piece.x = game.target.delta[i][0];
		piece_piece.y = game.target.delta[i][1];
		count = overlap(game, best_spot, piece_piece, count);
		if (count > 1 || count < 0)
			return (1);
		block++;
	}
	return (0);
}

t_point			solve(t_game *filler, int x, int y, int overlap)
{
	int			blocks;
	t_point		anchor;
	int			i;

	i = 0;
	blocks = where_anchor(filler, 0, 0);
	anchor = filler->target;
	filler->target.delta = ft_memalloc(sizeof(int *) * blocks + 1);
	block_find(filler, anchor, 0, 0);
	while (filler->list)
	{
		if (diff_blocks(*filler, blocks, filler->list->index))
			filler->list = filler->list->next;
		else
		{
			if (!filler->list)
			{
				filler->target.x = 0;
				filler->target.y = 0;
				return (filler->target);
			}
			break ;
		}
	}
	filler->target.x = filler->me_blocks[filler->list->index].x - anchor.x;
	filler->target.y = filler->me_blocks[filler->list->index].y - anchor.y;
	return (filler->target);
}
*/

/*	while (filler->list)
**	{
**		x =
**		filler->me_blocks[filler->list->index].x + filler->target.delta[i][0];
**		y =
**		filler->me_blocks[filler->list->index].y + filler->target.delta[i][1];
**		if (overlap > 1 || y < 0 || y > filler->board.tall ||
**							x < 0 || x > filler->board.wide ||
**			filler->board.data[y][x] == filler->you.id)
**		{
**			i = 0;
**			overlap = 0;
**			filler->list = filler->list->next;
**			if (!filler->list)
**			{
**				filler->target.x = 0;
**				filler->target.y = 0;
**				return (filler->target);
**			}
**			continue ;
**		}
**		if (filler->board.data[y][x] == filler->me.id)
**			overlap++;
**		i++;
**		if (i == blocks)
**		{
**			if (overlap == 1)
**			{
**				filler->target.y = filler->me_blocks[filler->list->index].y - anchor.y;
**				filler->target.x = filler->me_blocks[filler->list->index].x - anchor.x;
**				return (filler->target);
**			}
**			else
**			{
**				filler->target.x = 0;
**				filler->target.y = 0;
**				break ;
**			}
**		}
**	}
**	return (filler->target);
*/

/*
**	printf("X: %d %d %d\n", filler->target.x, filler->buf_me[filler->list->diff].x, anchor.x);
**	printf("Y: %d %d %d\n", filler->target.y, filler->buf_me[filler->list->diff].y, anchor.y);
**	return (filler->target);
*/

/*
**	while (filler.list) TO PRINT OUT BEST PLACEMENT BASED ON X / Y DIFF
**	{
**		ft_printf("[%s], x: %d, y: %d\n", filler.list->priority,
**			filler.buf_me[filler.list->diff].x,
**			filler.buf_me[filler.list->diff].y);
**		filler.list = filler.list->next;
**	}
*/

static void		set_list(t_game *filler, int to_match, int mode, int i)
{
	t_score		*list;

	score_list_init(&list, filler->me_blocks[0]);
	filler->scores = list;
	while (i < filler->me_count)
	{
		do_phase(filler, list, to_match, mode);
		if (list->score < INT32_MAX)
		{
			list = list->next;
			score_list_init(&list, filler->me_blocks[i]);
		}
		i++;
	}
	filler->scores = sort_scores(filler->scores);
}

/*
**	sets trigger to indicate first placements to early game.
**	sets and sorts list of scores for valid block placements.
*/

int				phase_one(t_game filler, int mode, int ch)
{
	int		max;
	while (++ch < 2)
	{
		if ((!ch ? filler.board.max[ch] >= (filler.board.wide * 66) / 100 :
				filler.board.max[ch] >= (filler.board.tall * 66) / 100) ||
			filler.me_count > (filler.board.size / 8))
			return (END_PHASE_1);
	}
	mode = filler.piece.max[0] >= filler.piece.max[1] ? 0 : 1;
	max = filler.board.max[mode] + filler.piece.max[mode];
	ch = -1;
	set_list(&filler, max, mode, 0);
/*	Testing BEGIN
	printf("BC: %d\n", filler.scores->rotation->block_count);
	while (filler.scores->rotation)
	{
		printf("BEST: %d\n", filler.scores->score);
		printf("SCORE: %d\n", filler.scores->rotation->score);
		filler.scores->rotation = filler.scores->rotation->next;
	}
//	Testing END
*/
	return (0);
}

/*
**	make decision where to place in three phase process.
*/

void			play_piece(t_game filler)
{
	t_point			target;
//	t_index			*alt_list;
	int				decision;

	decision = 0;
	decision |= phase_one(filler, 0, -1);
//	diff_piece(filler.piece.max, &filler, 0, 0);
//	alt_list = sort_diffs(&filler, 0, 0,
//		filler.piece.max[0] >= filler.piece.max[1] ? 0 : 1);
//	diff_mergesort(&filler.list);
//	diff_mergesort(&alt_list);
//	list_join(&filler.list, &alt_list);
//	while (filler.list)
//	while (alt_list)
//	{
//		ft_putnbr(filler.list->index);
//		ft_putnbr(alt_list->index);
//		write(1, ", ", 2);
//		filler.list = filler.list->next;
//		alt_list = alt_list->next;
//	}
//	write(1, "\n", 1);
//	target = solve(&filler, 0, 0, 0);
//	free_shit(&filler);
	ft_putnbr(target.y);
	ft_putchar(' ');
	ft_putnbr(target.x);
	ft_putchar('\n');
}
