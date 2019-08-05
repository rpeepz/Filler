/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/05 15:36:53 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	free remaining allocated pointers by the end of the game.
*/

static void		free_filler(t_game *filler, char *str, int b, int p)
{
	ft_memdel((void **)&filler->me_blocks);
	ft_memdel((void **)&filler->you_blocks);
	while (b < filler->board.tall)
	{
		str = filler->board.data[b];
		ft_strdel(&str);
		b++;
	}
	while (p < filler->piece.tall)
	{
		str = filler->board.data[p];
		ft_strdel(&str);
		p++;
	}
	ft_memdel((void **)&filler->board.data);
	ft_memdel((void **)&filler->piece.data);
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
**	loop thru stdout sets board and piece tokens.
**	find properties of piece and board.
*/

static void		begin_game(t_game filler, char **line)
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
			play_piece(filler);
		}
		ft_strdel(line);
	}
	free_filler(&filler, "", 0, 0);
}

/*
**	main function
**
**	checks for proper start conditions and inits game struct.
*/

int				main(void)
{
	char	*line;
	t_game	filler;

	line = NULL;
	if (get_next_line(0, &line) > 0 && (!ft_strncmp(line, "$$$ exec p", 9)))
	{
		ft_bzero(&filler, sizeof(t_game));
		filler.me_blocks = NULL;
		filler.you_blocks = NULL;
		filler.me.id = (line[10] == '1' ? 'O' : 'X');
		filler.you.id = (line[10] == '1' ? 'X' : 'O');
		begin_game(filler, &line);
	}
	else
		return (1);
	return (0);
}
