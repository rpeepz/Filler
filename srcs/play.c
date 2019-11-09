/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/22 05:52:02 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	allocate list of scores for determining best play spot
*/

static void		score_list_init(t_point point, t_score **list)
{
	t_score		*scores;

	scores = ft_memalloc(sizeof(t_score));
	scores->rotation = ft_memalloc(sizeof(t_try));
	scores->score = INT32_MAX;
	scores->board_point = point;
	scores->target = (t_point){0, 0};
	scores->rotation->target = (t_point){0, 0};
	scores->rotation->block = NULL;
	scores->next = NULL;
	*list = scores;
}

/*
**	initializes list of scores, calls phase one for every block filled by me.
*/

static void		set_list(t_game *filler, int max, int mode, int i)
{
	int			mo[3];
	t_score		*list;

	list = NULL;
	score_list_init(filler->me_blocks[0], &list);
	mo[0] = max;
	mo[1] = mode;
	filler->scores = list;
	while (++i < filler->me_count + 1)
	{
		mo[2] = INT32_MAX;
		phase_one(filler, list, mo, 0);
		list->target = list->rotation->target;
		if (list->score < filler->score)
		{
			filler->score = list->score;
			filler->target = list->target;
		}
		list->board_point = filler->me_blocks[i];
	}
	if (list->rotation)
		free(list->rotation);
	if (list)
		free(list);
}

/*
**	sets trigger to indicate first placements in early game.
**	sets and sorts list of scores for valid block placements.
**	TODO
**	return (END_PHASE_1);' after first if condition to initiate phase two
*/

static int		check_phase(t_game *filler, int max, int mode, int ch)
{
	while (++ch < 2)
	{
		if ((!ch ? filler->board.max[ch] >= (filler->board.wide * 66) / 100 :
				filler->board.max[ch] >= (filler->board.tall * 66) / 100) ||
			filler->me_count > (filler->board.size / 8))
			;
	}
	mode = filler->piece.max[0] >= filler->piece.max[1] ? 0 : 1;
	max = filler->board.max[mode] + filler->piece.max[mode];
	ch = -1;
	filler->score = INT32_MAX;
	set_list(filler, max, mode, -1);
	return (0);
}

/*
**	make decision where to place in (planned three) phase process.
*/

void			play_piece(t_game filler)
{
	int				decision;

	decision = 0;
	decision |= check_phase(&filler, 0, 0, -1);
	ft_putnbr(filler.target.y);
	ft_putchar(' ');
	ft_putnbr(filler.target.x);
	ft_putchar('\n');
}
