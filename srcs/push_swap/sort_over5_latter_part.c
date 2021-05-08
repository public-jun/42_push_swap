/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_latter_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:16:08 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 17:55:08 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_wrap(t_list_group *list_group, t_info *info)
{
	t_num_list_node	*stack_a;
	t_num_list_node	*stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	while (stack_a->next->num != 0)
	{
		if (stack_a->next->num != 0)
			exec_p_and_add_instr_node(stack_a, stack_b, list_group, info);
		serch_want(list_group, info);
	}
}

void	push_up_to_pivot(int pivot, t_list_group *list_group, t_info *info)
{
	while (list_group->stack_a->next->num < pivot
		&& info->want != info->all_size)
	{
		exec_p_and_add_instr_node(list_group->stack_a,
			list_group->stack_b, list_group, info);
		serch_want(list_group, info);
	}
}

void	sort_over5_latter(t_list_group *list_group, t_info *info)
{
	int	tmp_pivot;

	tmp_pivot = 0;
	if (count_pivot_node(info) > 1
		&& info->want == info->p_head->next->p_value)
		push_up_to_pivot(info->p_head->next->next->p_value, list_group, info);
	else if (count_pivot_node(info) > 0
		&& info->want < info->p_head->next->p_value)
		push_up_to_pivot(info->p_head->next->p_value, list_group, info);
	else
		 sort_wrap(list_group, info);
}
