/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only_3_node2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:57:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/05 22:38:40 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_only_three_case1(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group, info);
	else
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group, info);
}

void	sort_only_three_case2(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	if (stack == list_group->stack_a)
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group, info);
		exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group, info);
	}
	else
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group, info);
		exec_s_r_and_add_instr_node(exec_rr, stack, "rrb", list_group, info);
	}
}

void	sort_only_three_case3(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group, info);
	else
		exec_s_r_and_add_instr_node(exec_r, stack, "rb", list_group, info);
}

void	sort_only_three_case4(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	if (stack == list_group->stack_a)
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sa", list_group, info);
		exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group, info);
	}
	else
	{
		exec_s_r_and_add_instr_node(exec_s, stack, "sb", list_group, info);
		exec_s_r_and_add_instr_node(exec_r, stack, "rb", list_group, info);
	}
}

void	sort_only_three_case5(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	if (stack == list_group->stack_a)
		exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group, info);
	else
		exec_s_r_and_add_instr_node(exec_rr, stack, "rrb", list_group, info);
}
