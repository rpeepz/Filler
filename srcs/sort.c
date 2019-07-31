/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:06:56 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/31 15:55:20 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_score		*sorted_merge(t_score *a, t_score *b)
{
	t_score		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->score <= b->score)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void		split_lists(t_score *source, t_score **frontref, t_score **backref)
{
	t_score		*fast;
	t_score		*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void			sort_scores(t_score **scores)
{
	t_score		*head;
	t_score		*a;
	t_score		*b;

	head = *scores;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split_lists(head, &a, &b);
	sort_scores(&a);
	sort_scores(&b);
	*scores = sorted_merge(a, b);
}
