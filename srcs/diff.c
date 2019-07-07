/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:35:02 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:51:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			diff_piece(int *piece, t_game *filler, int i, int j)
{
	while (i < filler->me_count)
	{
		filler->me_blocks[i].delta =
			ft_memalloc(sizeof(int*) * filler->you_count);
		j = 0;
		while (j < filler->you_count)
		{
			filler->me_blocks[i].delta[j] = ft_memalloc(sizeof(int) * 2);
			filler->me_blocks[i].delta[j][0] =
				ABS(filler->me_blocks[i].x -
					filler->you_blocks[j].x) - piece[0];
			filler->me_blocks[i].delta[j][1] =
				ABS(filler->me_blocks[i].y -
					filler->you_blocks[j].y) - piece[1];
			j++;
		}
		i++;
	}
}

void			game_array_init(t_index *list, int index, int diff)
{
	if (!list)
	{
		list = ft_memalloc(sizeof(t_index));
		list->index = index;
		list->diff = diff;
		list->next = NULL;
	}
	else
	{
		game_array_push((t_index*)&list, index, diff);
	}
}

t_index			*sort_diffs(t_game *filler, int i, int j, int mode)
{
	int			min_diff;
	int			alt_diff;
	t_index		*alt_list;

	alt_list = NULL;
	min_diff = (mode == 1 ? filler->board.tall : filler->board.wide);
	alt_diff = (mode == 1 ? filler->board.wide : filler->board.tall);
	while (i < filler->me_count)
	{
		j = 0;
		while (j < filler->you_count)
		{
			if (filler->me_blocks[i].delta[j][mode] < min_diff)
				min_diff = filler->me_blocks[i].delta[j][mode];
			if (filler->me_blocks[i].delta[j][ABS(mode - 1)] < alt_diff)
				min_diff = filler->me_blocks[i].delta[j][mode];
			j++;
		}
		game_array_init(filler->list, i, min_diff);
		game_array_init(alt_list, i, alt_diff);
		i++;
	}
	return (alt_list);
}

/*
** POTENTIAL REWORK FOR WRAPPING IN BLOCK FIND
*/

void			block_find(t_game *filler, t_point anchor, int x, int y)
{
	int		i;

	i = 0;
	while (y < filler->piece.tall)
	{
		x = 0;
		while (x < filler->piece.wide)
		{
			if (filler->piece.data[y][x] == '*')
			{
				filler->target.delta[i] = ft_memalloc(sizeof(int) * 2);
				filler->target.delta[i][0] = y - anchor.y;
				filler->target.delta[i][1] = x - anchor.x;
				i++;
			}
			x++;
		}
		y++;
	}
}
