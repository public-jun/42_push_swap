/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:05:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/05 22:28:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pair_swap(t_pair *a, t_pair *b)
{
	int tmp_value;
	int tmp_id;

	tmp_value = a->value;
	tmp_id = a->id;
	a->value = b->value;
	a->id = b->id;
	b->value = tmp_value;
	b->id = tmp_id;
}

int	partition_value(t_pair n[], int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (i < j && n[++i].value < n[pivot].value)
			;
		while (j && n[pivot].value < n[--j].value)
			;
		if (i < j)
			pair_swap(&n[i], &n[j]);
	}
	pair_swap(&n[pivot], &n[j]);
	return (j);
}

int	partition_id(t_pair n[], int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (n[++i].id < n[pivot].id)
			;
		while (n[pivot].id < n[--j].id)
			;
		if (i < j)
			pair_swap(&n[i], &n[j]);
	}
	pair_swap(&n[pivot], &n[j]);
	return (j);
}

void	quick_sort(t_pair n[], int left, int right, int flag)
{
	int		pivot;

	if (left < right)
	{
		if (flag == SORT_VALUE)
			pivot = partition_value(n, left, right);
		if (flag == SORT_ID)
			pivot = partition_id(n, left, right);
		quick_sort(n, left, pivot - 1, flag);
		quick_sort(n, pivot + 1, right, flag);
	}
}
