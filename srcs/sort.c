/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:06:56 by rpapagna          #+#    #+#             */
/*   Updated: 2019/07/07 15:07:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_index		*sorted_merge(t_index *a, t_index *b)
{
	t_index		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->diff <= b->diff)
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

void		split_lists(t_index *source, t_index **frontref, t_index **backref)
{
	t_index		*fast;
	t_index		*slow;

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

void		diff_mergesort(t_index **headlist)
{
	t_index		*head;
	t_index		*a;
	t_index		*b;

	head = *headlist;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split_lists(head, &a, &b);
	diff_mergesort(&a);
	diff_mergesort(&b);
	*headlist = sorted_merge(a, b);
}

void		list_join(t_index **head, t_index **alt_list)
{
	t_index		*list;

	list = *head;
	while (list)
	{
		list = list->next;
	}
	list = *alt_list;
}
