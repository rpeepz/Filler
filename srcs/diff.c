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
		filler->buf_me[i].delta = ft_memalloc(sizeof(int*) * filler->you_count);
		j = 0;
		while (j < filler->you_count)
		{
			filler->buf_me[i].delta[j] = ft_memalloc(sizeof(int) * 2);
			filler->buf_me[i].delta[j][0] =
				ABS(filler->buf_me[i].x - filler->buf_you[j].x) - piece[0];
			filler->buf_me[i].delta[j][1] =
				ABS(filler->buf_me[i].y - filler->buf_you[j].y) - piece[1];
			j++;
		}
		i++;
	}
}

void			process_diff(t_game *filler, int i, int j, int z)
{
	int		tmp;

	tmp = (z == 1 ? filler->board.tall : filler->board.wide);
	while (i < filler->me_count)
	{
		j = 0;
		while (j < filler->you_count)
		{
			if (filler->buf_me[i].delta[j][z] <= tmp)
			{
				tmp = filler->buf_me[i].delta[j][z];
				if (!filler->list)
				{
					filler->list = ft_memalloc(sizeof(t_array));
					filler->list->diff = i;
					filler->list->priority = (z == 1 ? "tall" : "wide");
					filler->list->next = NULL;
				}
				else
					game_array_push(&filler->list, i);
			}
			j++;
		}
		i++;
	}
}

/*
** POTENTIAL REWORK FOR WRAPPING IN BLOCK FIND
*/

void			block_find(t_game *filler, t_where anchor, int x, int y)
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
