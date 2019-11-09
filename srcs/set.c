/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/08 01:02:26 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	setting board data or piece data
*/

void			set_token(t_token *token, char *info, int i, int type)
{
	char	*line;

	if (token->data)
		ft_memdel((void **)&token->data);
	line = ft_strchr(info, ' ') + 1;
	token->tall = ft_atoi(line);
	token->wide = ft_atoi(ft_strchr(line, ' '));
	token->size = token->tall * token->wide;
	if (type)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(sizeof(char *) * token->tall);
	while (i < token->tall)
	{
		get_next_line(0, &line);
		token->data[i] = ft_strdup(line + (type * 4));
		free(line);
		i++;
	}
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

/*
**	for each block filled by either player, assigns x,y value to
**	t_point pointer at an increasing index, which totals max spots taken
**	by either player stored in me/you count.
*/

void			whose_blocks(t_game *filler)
{
	t_point	point;

	filler->me_count = 0;
	filler->you_count = 0;
	point.y = 0;
	while (point.y < filler->board.tall)
	{
		point.x = 0;
		while (point.x < filler->board.wide)
		{
			if (filler->board.data[point.y][point.x] == filler->me_id)
				filler->me_blocks[filler->me_count++] = point;
			else if (filler->board.data[point.y][point.x] == filler->you_id)
				filler->you_blocks[filler->you_count++] = point;
			point.x++;
		}
		point.y++;
	}
	set_max(&filler->piece, 0, 0);
	set_max(&filler->piece, 0, 1);
	set_max(&filler->board, (int)filler->me_id, 0);
	set_max(&filler->board, (int)filler->me_id, 1);
}

/*
**	allocate for total blocks in board a pointer to t_point for both players.
*/

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
	whose_blocks(filler);
}
