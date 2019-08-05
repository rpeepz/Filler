/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/05 15:29:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	helper function for set token
**	free info in token
*/

void			free_token(t_token *token, char *str, int i, int offset)
{
	if (!token->data)
		return ;
	while (i < token->tall)
	{
		str = token->data[i] - offset;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&token->data);
}

/*
**	setting board data or piece data
*/

void			set_token(t_token *token, char *line, int i, int type)
{
	free_token(token, "", i, (type * 4));
	line = ft_strchr(line, ' ') + 1;
	token->tall = ft_atoi(line);
	token->wide = ft_atoi(ft_strchr(line, ' '));
	token->size = token->tall * token->wide;
	if (type)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(sizeof(char *) * token->tall);
	while (i < token->tall && get_next_line(0, &line))
	{
		token->data[i] = line + (type * 4);
		i++;
	}
}

/*
**	helper function for set start
*/

static void		set_players(t_game *filler, int y, int x, char id)
{
	if (id)
	{
		filler->me.id == 'X' ? (filler->me.start.y = y) :
			(filler->you.start.y = y);
		filler->me.id == 'X' ? (filler->me.start.x = x) :
			(filler->you.start.x = x);
	}
	else
	{
		filler->me.id == 'O' ? (filler->me.start.y = y) :
			(filler->you.start.y = y);
		filler->me.id == 'O' ? (filler->me.start.x = x) :
			(filler->you.start.x = x);
	}
}

/*
**	setting start location for each player
*/

void			set_start(t_game *filler)
{
	int		y;
	int		index_x;
	int		index_o;

	y = 0;
	index_o = -1;
	index_x = -1;
	while (y < filler->board.tall)
	{
		index_o = (index_o < 0 ? ft_strchri(filler->board.data[y], 'O') : -1);
		index_x = (index_x < 0 ? ft_strchri(filler->board.data[y], 'X') : -1);
		if (index_o >= 0)
			set_players(filler, y, index_o, 0);
		else if (index_x >= 0)
			set_players(filler, y, index_x, 1);
		y++;
	}
	filler->start = 1;
}

/*
**	find max filled hight or width of given token and stores in toke->max[].
*/

void			set_max(t_token *token, int type, int mode)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	token->max[mode] = 0;
	while (x < (mode == 1 ? token->tall : token->wide))
	{
		y = 0;
		while (y < (mode == 1 ? token->wide : token->tall))
		{
			if (token->data[(mode == 1 ? x : y)][(mode == 1 ? y : x)] ==
				(!type ? '*' : type))
			{
				token->max[mode]++;
				break ;
			}
			y++;
		}
		x++;
	}
}
