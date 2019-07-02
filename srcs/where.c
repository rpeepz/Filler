/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:32:55 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:16:17 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			who_where(t_game *filler)
{
	t_where	point;

	filler->me_count = 0;
	filler->you_count = 0;
	point.y = 0;
	while (point.y < filler->board.tall)
	{
		point.x = 0;
		while (point.x < filler->board.wide)
		{
			if (filler->board.data[point.y][point.x] == filler->me.id)
				filler->buf_me[filler->me_count++] = point;
			else if (filler->board.data[point.y][point.x] == filler->you.id)
				filler->buf_you[filler->you_count++] = point;
			point.x++;
		}
		point.y++;
	}
}

int				where_anchor(t_game *filler, int x, int y)
{
	int			blocks;

	blocks = 0;
	while (y < filler->piece.tall)
	{
		x = 0;
		while (x < filler->piece.wide)
		{
			if (filler->piece.data[y][x] == '*')
			{
				if (!blocks)
				{
					filler->target.x = x;
					filler->target.y = y;
				}
				blocks++;
			}
			x++;
		}
		y++;
	}
	return (blocks);
}
