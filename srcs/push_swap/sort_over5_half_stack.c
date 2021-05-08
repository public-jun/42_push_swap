/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_half_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:39:21 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 17:54:36 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	halve_set2(int b_min_count, t_info *info, t_list_group *list_group)
{
	int				push_count;
	t_num_list_node	*stack_a;
	t_num_list_node	*stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	push_count = 0;
	while (push_count < b_min_count)
	{
		exec_s_r_and_add_instr_node(exec_rr, stack_b, "rrb", list_group, info);
		exec_p_and_add_instr_node(stack_b, stack_a, list_group, info);
		push_count++;
	}
	while (push_count)
	{
		exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", list_group, info);
		push_count--;
	}
	while (stack_b->prev->num == info->want)
	{
		exec_s_r_and_add_instr_node(exec_rr, stack_b, "rrb", list_group, info);
		exec_p_and_add_instr_node(stack_b, stack_a, list_group, info);
		exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", list_group, info);
	}
}

void	pb_large_and_ra_small(int pivot, int *b_min_count,
	t_list_group *list_group, t_info *info)
{
	t_num_list_node	*tmp;

	tmp = list_group->stack_a->next;
	if (tmp->num < pivot)
	{
		exec_p_and_add_instr_node(list_group->stack_a,
			list_group->stack_b, list_group, info);
		if (list_group->stack_b->next->num == *b_min_count)
		{
			exec_s_r_and_add_instr_node(exec_r,
				list_group->stack_b, "rb", list_group, info);
			(*b_min_count)++;
		}
	}
	else
		exec_s_r_and_add_instr_node(exec_r,
			list_group->stack_a, "ra", list_group, info);
}

void	halve_set(t_info *info, t_list_group *list_group)
{
	int				pivot;
	int				b_min_count;

	pivot = info->all_size / 2;
	add_front_pivot_list(pivot, list_group, info);
	b_min_count = 0;
	while (info->b_size != pivot)
		pb_large_and_ra_small(pivot, &b_min_count, list_group, info);
	halve_set2(b_min_count, info, list_group);
}
