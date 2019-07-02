/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:41:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/06/24 20:37:34 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <stdio.h>
# define ABS(x) (x < 0 ? -(x) : x)
# define MAX(a, b) return (a > b ? a : b)
# define MIN(a, b) return (a < b ? a : b)

/*
**	--------------------------------
**				STRUCTS
**	---------------------------------
*/

typedef struct	s_where
{
	int			x;
	int			y;
	int			**delta;
}				t_where;

typedef struct	s_who
{
	char		id;
	t_where		start;
}				t_who;

typedef struct	s_what
{
	int			wide;
	int			tall;
	int			size;
	char		**data;
}				t_what;

typedef struct	s_game
{
	t_who		me;
	t_who		you;
	t_what		board;
	t_what		piece;
	t_where		target;
	char		*map;
	int			me_count;
	int			you_count;
	char		start;
	t_where		*buf_me;
	t_where		*buf_you;
}				t_game;

/*
**	--------------------------------
**				FUNCTIONS
**	---------------------------------
*/

void			set_what(t_what *token, char *line, int i, int type);
void			set_where(t_game *filler);
void			set_start(t_game *filler);
int				dist(t_where a, t_where b);
void			play_piece(t_game filler);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
#endif
