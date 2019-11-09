/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/08 01:02:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	free remaining allocated pointers by the end of the game.
*/

static void		free_filler(t_game *filler, int i, int type)
{
	if (!type)
	{
		while (type < filler->board.tall)
		{
			free(filler->board.data[type]);
			type++;
		}
		while (i < filler->piece.tall)
		{
			free(filler->piece.data[i]);
			i++;
		}
	}
	else
	{
		if (filler->me_blocks)
			ft_memdel((void **)&filler->me_blocks);
		if (filler->you_blocks)
			ft_memdel((void **)&filler->you_blocks);
		if (filler->board.data)
			ft_memdel((void **)&filler->board.data);
		if (filler->piece.data)
			ft_memdel((void **)&filler->piece.data);
	}
}

/*
**	loop thru stdout sets board and piece tokens.
**	find properties of piece and board.
*/

static void		begin_game(t_game filler)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			continue;
		if (!ft_strncmp(line, "Plateau", 7))
			set_token(&filler.board, line, 0, 1);
		else if (!ft_strncmp(line, "Piece", 5))
		{
			set_token(&filler.piece, line, 0, 0);
			set_blocks(&filler);
			play_piece(filler);
			free_filler(&filler, 0, 0);
		}
		ft_strdel(&line);
	}
	free_filler(&filler, 0, 1);
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
		filler.me_id = (line[10] == '1' ? 'O' : 'X');
		filler.you_id = (line[10] == '1' ? 'X' : 'O');
		free(line);
		begin_game(filler);
	}
	else
		return (1);
	return (0);
}
