/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_first_part.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:15:31 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 17:47:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_operation_in_b_quick_sort(int pivot, t_num_list_node **end,
t_list_group *list_group, t_info *info)
{
	if (list_group->stack_b->next->num == info->want)
	{
		exec_p_and_add_instr_node(list_group->stack_b,
			list_group->stack_a, list_group, info);
		exec_s_r_and_add_instr_node(exec_r,
			list_group->stack_a, "ra", list_group, info);
	}
	else if (list_group->stack_b->next->num >= pivot)
		exec_p_and_add_instr_node(list_group->stack_b,
			list_group->stack_a, list_group, info);
	else
	{
		if (!(*end))
			*end = list_group->stack_b->next;
		exec_s_r_and_add_instr_node(exec_r,
			list_group->stack_b, "rb", list_group, info);
	}
}

void	b_quick_sort(t_list_group *list_group, t_info *info)
{
	int				pivot;
	t_num_list_node	*end;

	pivot = (info->b_size / 2) + info->want;
	end = NULL;
	add_front_pivot_list(pivot, list_group, info);
	while (list_group->stack_b->next != end
		&& info->b_size > 0 && list_group->stack_a->prev != end)
		sort_operation_in_b_quick_sort(pivot, &end, list_group, info);
	serch_want(list_group, info);
}

void	sort_remain_node(t_list_group *group, t_info *info)
{
	int	min;

	while (group->stack_b->next != group->stack_b)
	{
		if (info->b_size > 1)
		{
			min = find_min_value(group->stack_b);
			min_move_top(group->stack_b, min, info, group);
		}
		exec_p_and_add_instr_node(group->stack_b, group->stack_a, group, info);
		exec_s_r_and_add_instr_node(exec_r, group->stack_a, "ra", group, info);
	}
	serch_want(group, info);
}

void	sort_over5(t_list_group *list_group, t_info *info)
{
	info->b_min = info->want;
	halve_set(info, list_group);
	while (info->want != info->all_size)
	{
		while (info->b_size > 4)
			b_quick_sort(list_group, info);
		if (info->b_size)
			sort_remain_node(list_group, info);
		if (info->want == info->all_size)
			break ;
		sort_over5_latter(list_group, info);
		info->b_min = info->want;
	}
}
