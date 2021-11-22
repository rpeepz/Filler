/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:16:03 by rpapagna          #+#    #+#             */
/*   Updated: 2021/11/22 19:21:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libbignum.h"

//TODO
//figure out how to add negative with positive numbers
//subtraction function

char				do_minus(size_t* i, size_t* j, char* n1, char* n2)
{
	char	x;
	char	y;

	x = 0;
	y = 0;
	if (*i != 0)
	{
		--(*i);
		x = n1[*i] - '0';
	}
	if (*j != 0)
	{
		--(*j);
		y = n2[*j ] - '0';
	}
	if (x > y)
		return (x - y);
	return (y - x);
}

t_bignum*			add_negative(t_bignum* a1, t_bignum* a2, int b) //0 if a1 is negative, 1 if a2 is negative
{
	char	*n;

	n = (!b) ? (a1->number + 1) : (a2->number + 1);
	if (!b && !ft_strcmp(n ,a2->number))
		return (bignum_init("0"));
	if (!ft_strcmp(a1->number, n))
		return (bignum_init("0"));
	size_t	i;
	size_t	j;
	size_t	k;
	char*	dif;
	k = (a1->len > a2->len) ? a1->len : a2->len;
	dif = (char *)malloc(sizeof(char) * k + 1);
	i = 0;
	while (i < k)
		dif[i++] = '0';
	dif[i] = '\0';
	i = !b ? ft_strlen(n) : a1->len;
	j = !b ? a2->len : ft_strlen(n);
	while (!(i == 0 && j == 0))
	{
		--k;
		dif[k] += do_minus(&i, &j, !b ? n : a1->number, !b ? a2->number : n);
		if (dif[k] < '0')
		{
			dif[k] += 10;
			dif[k - 1] -= 1;
		}
	}
	t_bignum* tmp = bignum_init(n);
	if (!b)
	{
		if (!bignum_gt(tmp, a2))
			dif[0] = '-';
	}
	else
	{
		if (!bignum_gt(tmp, a1))
			dif[0] = '-';
	}
	bignum_del(&tmp);
	return (bignum_init(dif));
}

static char			do_add(size_t* i, size_t* j, char* n1, char* n2)
{
	char	x;

	x = 0;
	if (*i != 0)
	{
		--(*i);
		if (n1[*i] != '-')
			x += (n1[*i] - '0');
	}
	if (*j != 0)
	{
		--(*j);
		if (n2[*j] != '-')
			x += (n2[*j] - '0');
	}
	return (x);
}

t_bignum*			bignum_add(t_bignum* a1, t_bignum* a2)
{
	size_t	i; //indexer for a1
	size_t	j; //indexer for a2
	size_t	k; //indexer for sum
	char	*sum;

	if ((a1->sign == 1 && a2->sign == 0) || a1->sign == 0 && a2->sign == 1)
		return (add_negative(a1, a2, a1->sign == 1 ? 0 : 1));
	k = (a1->len > a2->len) ? a1->len : a2->len;
	k += (((a1->number[0] - '0') + (a2->number[0] - '0')) > 8) ? 1 : 0;
	sum = (char *)malloc(sizeof(char) * k + 1);
	i = 0;
	if (a1->sign == 1 && a2->sign == 1)
		sum[i++] = '-';
	while (i < k)
		sum[i++] = '0';
	sum[i] = '\0';
	i = a1->len;
	j = a2->len;
	while (!(i == 0 && j == 0))
	{
		--k;
		sum[k] += do_add(&i, &j, a1->number, a2->number);
		if (sum[k] > '9')
		{
			sum[k] -= 10;
			sum[k - 1] += 1;
		}
	}
	return (bignum_init(sum));
}


//unfinished and untested
t_bignum*			bignum_minus(t_bignum* m, t_bignum* s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char*	dif;

	while (!(i == 0 && j == 0))
	{
		--k;
		dif[k] -= do_add(&i, &j, m->number, s->number);
		if (dif[k] < '0')
		{
			dif[k] += 10;
			dif[k - 1] -= 1;
		}
	}
	return (bignum_init(dif));
}

void				bignum_multiply(t_bignum* m1, t_bignum* m2, t_bignum* prod);
void				bignum_divide(t_bignum* d1, t_bignum* d2, t_bignum *q);
