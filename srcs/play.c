/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:56:04 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				count_links(t_array *link)
{
	int		i;

	i = 0;
	while (link)
	{
		link = link->next;
		i++;
	}
	return (i);
}

int				diff_blocks(t_game game, t_where anch, int blocks, t_array *pl)
{
	int		i;
	int		y;
	int		x;
	t_where	tmp;

	y = game.buf_me[pl->diff].y;
	x = game.buf_me[pl->diff].x;
	i = 0;
	while (i < blocks)
	{
		tmp.y = game.target.delta[i][0];
		tmp.x = game.target.delta[i][1];
		if (!position_valid(game, tmp))
			return (1);
		i++;
	}
	return (0);
}

t_where			solve(t_game *filler, int x, int y, int z)
{
	int		blocks;
	t_where	anchor;

	blocks = where_anchor(filler, 0, 0);
	anchor = filler->target;
	filler->target.delta = ft_memalloc(sizeof(int *) * blocks + 1);
	block_find(filler, anchor, 0, 0);
	while (filler->list)
	{
		if (diff_blocks(*filler, anchor, blocks, filler->list))
			filler->list = filler->list->next;
		else
			break ;
	}
	filler->target.x = filler->buf_me[filler->list->diff].x - anchor.x;
	filler->target.y = filler->buf_me[filler->list->diff].y - anchor.y;
	return (filler->target);
}

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
	int		piece[2];
	t_where	target;

	who_where(&filler);
	piece[0] = what_wide(filler.piece, 0, 0);
	piece[1] = what_tall(filler.piece, 0, 0);
	diff_piece(piece, &filler, 0, 0);
	process_diff(&filler, 0, 0, piece[0] >= piece[1] ? 0 : 1);
	game_array_rev(&filler.list);
	target = solve(&filler, 0, 0, 0);
//	free_shit(&filler);
	if (!position_valid(filler, target))
	{
		target.x = 0;
		target.y = 0;
		ft_putstr("0 0\n");
		exit(0);
	}
	ft_putnbr(target.y);
	ft_putchar(' ');
	ft_putnbr(target.x);
	ft_putchar('\n');
}
