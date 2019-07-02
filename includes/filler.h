/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:41:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:34:14 by rpapagna         ###   ########.fr       */
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

typedef struct		s_where
{
	int				x;
	int				y;
	int				**delta;
}					t_where;

typedef struct		s_who
{
	char			id;
	t_where			start;
}					t_who;

typedef struct		s_what
{
	int				wide;
	int				tall;
	int				size;
	char			**data;
}					t_what;

typedef struct		s_array
{
	int				diff;
	char			*priority;
	struct s_array	*next;
}					t_array;

typedef struct		s_game
{
	t_who			me;
	t_who			you;
	t_what			board;
	t_what			piece;
	t_where			target;
	char			*map;
	int				me_count;
	int				you_count;
	char			start;
	t_where			*buf_me;
	t_where			*buf_you;
	t_array			*list;
}					t_game;

/*
**	--------------------------------
**				FUNCTIONS
**	---------------------------------
*/

void				set_what(t_what *token, char *line, int i, int type);
void				set_where(t_game *filler);
void				set_start(t_game *filler);
void				diff_piece(int *piece, t_game *filler, int i, int j);
void				process_diff(t_game *filler, int i, int j, int z);
void				block_find(t_game *filler, t_where anchor, int x, int y);
void				game_array_push(t_array **alist, int data);
void				who_where(t_game *filler);
void				game_array_rev(t_array **alist);
int					where_anchor(t_game *filler, int x, int y);
int					what_wide(t_what piece, int x, int y);
int					what_tall(t_what piece, int x, int y);
int					position_valid(t_game filler, t_where point);
int					dist(t_where a, t_where b);
void				play_piece(t_game filler);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
#endif
