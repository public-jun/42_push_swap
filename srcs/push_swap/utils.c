/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:10:43 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 18:11:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	no_sort(t_list_group *list_group, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->all_size - 1)
	{
		if (info->n[i].value + 1 != info->n[i + 1].value)
			return ;
		i++;
	}
	ft_exit(list_group);
}

int	find_min_value(t_num_list_node *head)
{
	t_num_list_node	*tmp;
	t_num_list_node	*min;
	int				res;
	int				i;

	tmp = head->next;
	min = tmp;
	res = 0;
	i = 0;
	while (tmp != head)
	{
		if (tmp->num < min->num)
		{
			res = i;
			min = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (res);
}

static void	operation_move_top(t_num_list_node *stack,
	t_list_group *list_group, t_info *info, int dir_flag)
{
	if (dir_flag == 0)
	{
		if (stack == list_group->stack_a)
			exec_s_r_and_add_instr_node(exec_r, stack,
				"ra", list_group, info);
		else
			exec_s_r_and_add_instr_node(exec_r, stack,
				"rb", list_group, info);
	}
	else
	{
		if (stack == list_group->stack_a)
			exec_s_r_and_add_instr_node(exec_rr, stack,
				"rra", list_group, info);
		else
			exec_s_r_and_add_instr_node(exec_rr, stack,
				"rrb", list_group, info);
	}
}

void	min_move_top(t_num_list_node *stack, int min,
t_info *info, t_list_group *list_group)
{
	int	pivot;
	int	tmp;
	int	size;

	if (stack == list_group->stack_a)
		size = info->a_size;
	else
		size = info->b_size;
	pivot = size / 2;
	tmp = min;
	if (min <= pivot)
	{
		while (tmp-- > 0)
			operation_move_top(stack, list_group, info, 0);
	}
	else
	{
		while (tmp++ < size)
			operation_move_top(stack, list_group, info, 1);
	}
}

void	pa_all_node(t_list_group *list_group, t_info *info)
{
	t_num_list_node	*tmp;

	tmp = list_group->stack_b->next;
	while (tmp != list_group->stack_b)
	{
		tmp = tmp->next;
		exec_p_and_add_instr_node(list_group->stack_b,
			list_group->stack_a, list_group, info);
	}
}
