/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:05:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 19:35:12 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_more_four_less_six(t_num_list_node *stack,
	t_list_group *list_group, t_info *info)
{
	int	min;

	while (info->a_size != 3)
	{
		min = find_min_value(stack);
		min_move_top(stack, min, info, list_group);
		exec_p_and_add_instr_node(list_group->stack_a,
			list_group->stack_b, list_group, info);
	}
	sort_only_three(stack, list_group, info);
	pa_all_node(list_group, info);
}

void	sort_less6(t_info *info, t_list_group *list_group)
{
	t_num_list_node	*stack_a;

	stack_a = list_group->stack_a;
	if (info->all_size == 1)
		ft_exit_ps(list_group, info);
	else if (info->all_size == 2)
	{
		if (stack_a->next->num > stack_a->next->next->num)
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa",
				list_group, info);
	}
	else if (info->all_size == 3)
		sort_only_three(stack_a, list_group, info);
	else if (info->all_size <= 5 )
		sort_more_four_less_six(stack_a, list_group, info);
}
