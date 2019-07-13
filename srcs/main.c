/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/02 05:56:31 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	for each block filled by either player assigns x,y value
**	to t_point pointer at an increasing index, which totals max spots taken
**	by either player and stores in me/you count.
*/

static void		whose_blocks(t_game *filler)
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
			if (filler->board.data[point.y][point.x] == filler->me.id)
				filler->me_blocks[filler->me_count++] = point;
			else if (filler->board.data[point.y][point.x] == filler->you.id)
				filler->you_blocks[filler->you_count++] = point;
			point.x++;
		}
		point.y++;
	}
}

/*
**	allocate for total blocks in board a pointer to t_point for both players.
**	calls whose blocks
*/

static void		set_blocks(t_game *filler)
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

/*
**	find max filled hight or width of given token and stores in toke->max[].
*/

static void		set_max(t_token *token, int type, int mode)
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
**	loop thru stdout sets board and piece tokens.
**	find properties of piece and board.
**	calls play piece
*/

static void		begin_game(t_game filler, t_score *score_list, char **line)
{
	ft_strdel(line);
	while (get_next_line(0, line) > 0)
	{
		if (!*(line))
			continue;
		if (!ft_strncmp(*line, "Plateau", 7))
		{
			set_token(&filler.board, *line, 0, 1);
			if (!filler.start)
				set_start(&filler);
		}
		else if (!ft_strncmp(*line, "Piece", 5))
		{
			set_token(&filler.piece, *line, 0, 0);
			set_max(&filler.piece, 0, 0);
			set_max(&filler.piece, 0, 1);
			set_max(&filler.board, (int)filler.me.id, 0);
			set_max(&filler.board, (int)filler.me.id, 1);
			set_blocks(&filler);
			score_list_init(&filler, score_list, 0);
			play_piece(filler);
		}
		ft_strdel(line);
	}
}

/*
**	main function
**
**	checks for proper start and inits t_game struct.
**	calls begin game
*/

int				main(void)
{
	char	*line;
	t_score	*score_list;
	t_game	filler;

	line = NULL;
	if (get_next_line(0, &line) > 0 && (!ft_strncmp(line, "$$$ exec p", 9)))
	{
		ft_bzero(&filler, sizeof(t_game));
		filler.me_blocks = NULL;
		filler.you_blocks = NULL;
		filler.list = NULL;
		score_list = NULL;
		filler.me.id = (line[10] == '1' ? 'O' : 'X');
		filler.you.id = (line[10] == '1' ? 'X' : 'O');
		begin_game(filler, score_list, &line);
	}
	else
		return (1);
	return (0);
}
