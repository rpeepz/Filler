/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 06:11:48 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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

int				diff_blocks(t_game game, t_point anch, int blocks, t_index *pl)
{
	int		i;
	int		count;
	t_point	piece_piece;
	t_point best_spot;

	best_spot.y = game.me_blocks[pl->index].y;
	best_spot.x = game.me_blocks[pl->index].x;
	count = 0;
	i = 0;
	while (i < blocks)
	{
		piece_piece.y = game.target.delta[i][0];
		piece_piece.x = game.target.delta[i][1];
		count = overlap(game, best_spot, piece_piece, count);
		if (count > 1 || count < 0)
			return (1);
		i++;
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
		x =
		filler->me_blocks[filler->list->index].x + filler->target.delta[i][0];
		y =
		filler->me_blocks[filler->list->index].y + filler->target.delta[i][1];
		if (overlap > 1 || y < 0 || y > filler->board.tall ||
							x < 0 || x > filler->board.wide ||
			filler->board.data[y][x] == filler->you.id)
		{
			i = 0;
			overlap = 0;
			filler->list = filler->list->next;
			if (!filler->list)
			{
				filler->target.x = 0;
				filler->target.y = 0;
				return (filler->target);
			}
			continue ;
		}
		if (filler->board.data[y][x] == filler->me.id)
			overlap++;
		i++;
		if (i == blocks)
		{
			if (overlap == 1)
			{
				filler->target.y = filler->me_blocks[filler->list->index].y - anchor.y;
				filler->target.x = filler->me_blocks[filler->list->index].x - anchor.x;
				return (filler->target);
			}
			else
			{
				filler->target.x = 0;
				filler->target.y = 0;
				break ;
			}
		}
	}
	return (filler->target);
}

/*
**	printf("X: %d %d %d\n", filler->target.x, filler->buf_me[filler->list->diff].x, anchor.x);
**	printf("Y: %d %d %d\n", filler->target.y, filler->buf_me[filler->list->diff].y, anchor.y);
**	return (filler->target);
**	while (filler->list)
**	{
**		if (diff_blocks(*filler, anchor, blocks, filler->list))
**			filler->list = filler->list->next;
**		else
**		{
**			if (!filler->list)
**			{
**				filler->target.x = 0;
**				filler->target.y = 0;
**				return (filler->target);
**			}
**			break ;
**		}
**	}
**	filler->target.x = filler->buf_me[filler->list->diff].x - anchor.x;
**	filler->target.y = filler->buf_me[filler->list->diff].y - anchor.y;
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

void			play_piece(t_game filler)
{
	int				piece[2];
	t_point			target;
	t_index			*alt_list;

	whose_blocks(&filler);
	piece[0] = what_axis(filler.piece, 0, 0, 0);
	piece[1] = what_axis(filler.piece, 0, 0, 1);
	diff_piece(piece, &filler, 0, 0);
	alt_list = sort_diffs(&filler, 0, 0, piece[0] >= piece[1] ? 0 : 1);
	diff_mergesort(&filler.list);
	diff_mergesort(&alt_list);
	list_join(&filler.list, &alt_list);
	target = solve(&filler, 0, 0, 0);
//	free_shit(&filler);
	ft_putnbr(target.y);
	ft_putchar(' ');
	ft_putnbr(target.x);
	ft_putchar('\n');
}
