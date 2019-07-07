/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:28:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:16:32 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				position_valid(t_game filler, t_point point)
{
	return (point.x >= 0 && point.y >= 0 &&
			point.x < filler.board.wide && point.y < filler.board.tall);
}

void			game_array_push(t_index *list, int index, int diff)
{
	t_index	**real_list;
	t_index	*new_head;

	real_list = (t_index **)list;
	new_head = ft_memalloc(sizeof(t_index));
	new_head->index = index;
	new_head->diff = diff;
	new_head->next = *real_list;
	*real_list = new_head;
}

void			game_array_rev(t_index **alist)
{
	t_index	*prev;
	t_index	*cur;
	t_index	*next;

	prev = NULL;
	cur = *alist;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alist = prev;
}

int				what_axis(t_token piece, int x, int y, int type)
{
	int		axis;

	axis = 0;
	while (x < (type == 1 ? piece.tall : piece.wide))
	{
		y = 0;
		while (y < (type == 1 ? piece.wide : piece.tall))
		{
			if (piece.data[(type == 1 ? x : y)][(type == 1 ? y : x)] == '*')
			{
				axis++;
				break ;
			}
			y++;
		}
		x++;
	}
	return (axis);
}
