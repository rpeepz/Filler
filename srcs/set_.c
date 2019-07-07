/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/06/24 21:30:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		free_token(t_token *token, char *str, int i, int offset)
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

void			set_start(t_game *filler)
{
	int		y;
	int		i_x;
	int		i_o;

	y = 0;
	i_o = 0;
	i_x = 0;
	while (y < filler->board.tall)
	{
		i_o = (i_o == 0 ? ft_strchri(filler->board.data[y], 'O') : -1);
		i_x = (i_x == 0 ? ft_strchri(filler->board.data[y], 'X') : -1);
		if (i_o > 0)
			set_players(filler, y, i_o, 0);
		else if (i_x > 0)
			set_players(filler, y, i_x, 1);
		y++;
	}
	filler->start = 1;
}

void			set_blocks(t_game *filler)
{
	int		size;

	if (filler->me_blocks)
		ft_memdel((void **)&filler->me_blocks);
	if (filler->you_blocks)
		ft_memdel((void **)&filler->you_blocks);
	size = filler->board.size;
	if (!(filler->me_blocks = ft_memalloc(sizeof(t_point) * size)) ||
		!(filler->you_blocks = ft_memalloc(sizeof(t_point) * size)))
		exit(1);
	ft_bzero(filler->me_blocks, sizeof(t_point) * size);
	ft_bzero(filler->you_blocks, sizeof(t_point) * size);
}
