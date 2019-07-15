/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:41:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/14 19:06:34 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <stdio.h>
# define END_PHASE_1 0x1000
# define END_PHASE_2 0x2000
# define END_PHASE_3 0x4000
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
}					t_point;

typedef struct		s_who
{
	char			id;
	t_point			start;
}					t_who;

typedef struct		s_index
{
	int				index;
	int				diff;
	struct s_index	*next;
}					t_index;

typedef struct		s_token
{
	int				wide;
	int				tall;
	int				size;
	int				max[2];
	char			**data;
}					t_token;

typedef struct		s_try
{
	int				block_count;
	t_point			target;
	t_point			anchor;
	t_point			*block;
}					t_try;

typedef struct		s_score
{
	int				score;
	t_point			board_point;
	t_point			target;
	t_try			*rotation;
	struct s_score	*next;
}					t_score;

typedef struct		s_game
{
	char			start;
	int				me_count;
	int				you_count;
	t_point			target;
	t_point			*me_blocks;
	t_point			*you_blocks;
	t_who			me;
	t_who			you;
	t_index			*list;
	t_token			board;
	t_token			piece;
	t_score			*scores;
}					t_game;

/*
**	--------------------------------
**				FUNCTIONS
**	---------------------------------
*/

void				list_join(t_index **head, t_index **alt_list);
void				diff_mergesort(t_index **headlist);
void				game_array_push(t_index **list, int index, int diff);
void				diff_piece(int *piece, t_game *filler, int i, int j);
t_index				*sort_diffs(t_game *filler, int i, int j, int mode);
void				block_find(t_game *filler, t_point anchor, int x, int y);
void				game_array_rev(t_index **alist);
int					where_anchor(t_game *filler, int x, int y);
int					position_valid(t_game filler, t_point point);
int					dist(t_point a, t_point b);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

t_try				*sort_trys(t_try *list);
t_score				*sort_scores(t_score *scores);
void				do_phase(t_game *filler, t_score *scores, int *mo);
t_score				*score_list_init(t_point point);
void				play_piece(t_game filler);
void				set_start(t_game *filler);
void				set_token(t_token *token, char *line, int i, int type);
#endif
