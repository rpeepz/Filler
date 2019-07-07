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

typedef struct		s_point
{
	int				x;
	int				y;
	int				**delta;
}					t_point;

typedef struct		s_who
{
	char			id;
	t_point			start;
}					t_who;

typedef struct		s_token
{
	int				wide;
	int				tall;
	int				size;
	char			**data;
}					t_token;

typedef struct		s_index
{
	int				index;
	int				diff;
	struct s_index	*next;
}					t_index;

typedef struct		s_game
{
	t_who			me;
	t_who			you;
	t_token			board;
	t_token			piece;
	t_point			target;
	int				me_count;
	int				you_count;
	char			start;
	t_point			*me_blocks;
	t_point			*you_blocks;
	t_index			*list;
}					t_game;

/*
**	--------------------------------
**				FUNCTIONS
**	---------------------------------
*/

void				list_join(t_index **head, t_index **alt_list);
void				diff_mergesort(t_index **headlist);
void				game_array_push(t_index *list, int index, int diff);
void				set_token(t_token *token, char *line, int i, int type);
void				set_blocks(t_game *filler);
void				set_start(t_game *filler);
void				diff_piece(int *piece, t_game *filler, int i, int j);
t_index				*sort_diffs(t_game *filler, int i, int j, int mode);
void				block_find(t_game *filler, t_point anchor, int x, int y);
void				whose_blocks(t_game *filler);
void				game_array_rev(t_index **alist);
int					where_anchor(t_game *filler, int x, int y);
int					what_axis(t_token piece, int x, int y, int type);
int					position_valid(t_game filler, t_point point);
int					dist(t_point a, t_point b);
void				play_piece(t_game filler);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
#endif
