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

static void		begin_game(t_game filler, char **line)
{
	ft_strdel(line);
	while (get_next_line(0, line) > -1)
	{
		if (!*(line))
			continue;
		if (!ft_strncmp(*line, "Plateau", 7))
		{
			set_what(&filler.board, *line, 0, 1);
			if (!filler.start)
				set_start(&filler);
		}
		else if (!ft_strncmp(*line, "Piece", 5))
		{
			set_what(&filler.piece, *line, 0, 0);
			set_where(&filler);
			play_piece(filler);
		}
		else
			ft_strdel(line);
	}
}

int				main(void)
{
	t_game	filler;
	char	*line;

	ft_bzero(&filler, sizeof(t_game));
	line = NULL;
	filler.start = 0;
	if (get_next_line(0, &line) > 0 && (!ft_strncmp(line, "$$$ exec p", 9)))
	{
		filler.me.id = (line[10] == '1' ? 'O' : 'X');
		filler.you.id = (line[10] == '1' ? 'X' : 'O');
		begin_game(filler, &line);
	}
	else
		return (1);
	return (0);
}
