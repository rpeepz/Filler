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

int				position_valid(t_game filler, t_where point)
{
	return (point.x >= 0 && point.y >= 0 &&
			point.x < filler.board.wide && point.y < filler.board.tall);
}

void			game_array_push(t_array **alist, int data)
{
	t_array	*new_head;
	t_array	*old_head;

	old_head = *alist;
	new_head = ft_memalloc(sizeof(t_array));
	new_head->diff = data;
	new_head->priority = (*alist)->priority;
	new_head->next = old_head;
	*alist = new_head;
}

void			game_array_rev(t_array **alist)
{
	t_array	*prev;
	t_array	*cur;
	t_array	*next;

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

/*
** REFACTOR WHAT_WIDE AND WHAT_TALL
** scan col or row for existance of '*'
** if found immediately jump to next col or row
*/

int				what_wide(t_what piece, int x, int y)
{
	int		temp2;
	int		tmp;

	tmp = 0;
	temp2 = 0;
	while (y < piece.tall)
	{
		x = 0;
		while (x < piece.wide)
		{
			if (piece.data[y][x] == '*')
				tmp++;
			x++;
		}
		IF_THEN(temp2 < tmp, temp2 = tmp);
		tmp = 0;
		y++;
	}
	return (temp2);
}

int				what_tall(t_what piece, int x, int y)
{
	int		temp2;
	int		tmp;

	tmp = 0;
	temp2 = 0;
	while (x < piece.wide)
	{
		y = 0;
		while (y < piece.tall)
		{
			if (piece.data[y][x] == '*')
				tmp++;
			y++;
		}
		IF_THEN(temp2 < tmp, temp2 = tmp);
		tmp = 0;
		x++;
	}
	return (temp2);
}
