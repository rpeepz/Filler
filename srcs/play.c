/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:42:42 by rpapagna          #+#    #+#             */
/*   Updated: 2019/08/01 22:25:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
		phase_one(filler, list, mo);
		list->target = list->rotation->target;
		if (list->score < filler->score)
		{
			filler->score = list->score;
			filler->target = list->target;
		}
		list->board_point = filler->me_blocks[i];
	}
}

/*
**	sets trigger to indicate first placements in early game.
**	sets and sorts list of scores for valid block placements.
*/

int				check_phase(t_game *filler, int max, int mode, int ch)
{
	while (++ch < 2)
	{
		if ((!ch ? filler->board.max[ch] >= (filler->board.wide * 66) / 100 :
				filler->board.max[ch] >= (filler->board.tall * 66) / 100) ||
			filler->me_count > (filler->board.size / 8))
			;//return (END_PHASE_1);
	}
	mode = filler->piece.max[0] >= filler->piece.max[1] ? 0 : 1;
	max = filler->board.max[mode] + filler->piece.max[mode];
	ch = -1;
	filler->score = INT32_MAX;
	set_list(filler, max, mode, -1);
/*
//	Testing BEGIN
	printf("BlockCount[%d]\n", filler->scores->rotation->block_count);
	while (filler->scores)
	{
		printf("BestScore [%d]\n", filler->scores->score);
		filler->scores = filler->scores->next;
	}
//	Testing END
*/
	return (0);
}

/*
**	make decision where to place in three phase process.
*/

void			play_piece(t_game filler)
{
	int				decision;

	decision = 0;
	decision |= check_phase(&filler, 0, 0, -1);
//	free_shit(&filler);
	ft_putnbr(filler.target.y);
	ft_putchar(' ');
	ft_putnbr(filler.target.x);
	ft_putchar('\n');
}
