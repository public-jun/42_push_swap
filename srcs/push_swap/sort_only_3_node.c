/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only_3_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:57:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/27 17:01:53 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_only_three_case1(t_num_list_node *stack, t_list_group *list_group)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group);
	else
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group);
}

void	sort_only_three_case2(t_num_list_node *stack, t_list_group *list_group)
{
	if (stack == list_group->stack_a)
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group);
		exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group);
	}
	else
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group);
		exec_s_r_and_add_instr_node(exec_rr, stack, "rrb", list_group);
	}
}

void	sort_only_three_case3(t_num_list_node *stack, t_list_group *list_group)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group);
	else
		exec_s_r_and_add_instr_node(exec_r, stack, "rb", list_group);
}

void	sort_only_three_case4(t_num_list_node *stack, t_list_group *list_group)
{
	if (stack == list_group->stack_a)
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group);
		exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group);
	}
	else
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group);
		exec_s_r_and_add_instr_node(exec_r, stack, "rb", list_group);
	}
}

void	sort_only_three_case5(t_num_list_node *stack, t_list_group *list_group)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group);
	else
		exec_s_r_and_add_instr_node(exec_rr, stack, "rrb", list_group);
}
