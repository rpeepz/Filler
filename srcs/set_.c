/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/13 17:46:43 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	helper function for set token
**	free info in token
*/

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
**	allocate list of scores for determining best play spot
*/

void			score_list_init(t_game *filler, t_score *score_list, int i)
{
	t_score		*list;

	list = ft_memalloc(sizeof(t_score));
	list->score = INT32_MAX;
	list->board_point = filler->me_blocks[i];
	list->target = (t_point){0, 0};
	list->rotation = ft_memalloc(sizeof(t_try));
	list->rotation->score = INT32_MAX;
	list->rotation->block = NULL;
	list->rotation->next = NULL;
	list->next = score_list;
	filler->scores = list;
}
