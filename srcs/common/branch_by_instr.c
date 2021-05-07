/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_by_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:36:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 17:44:18 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	conditional_branch_by_instr2(char *instr, t_list_group *list_group)
{
	if (!(ft_strncmp(instr, "ra", 3)))
		exec_r(list_group->stack_a);
	else if (!(ft_strncmp(instr, "rb", 3)))
		exec_r(list_group->stack_b);
	else if (!(ft_strncmp(instr, "rr", 3)))
	{
		exec_r(list_group->stack_a);
		exec_r(list_group->stack_b);
	}
	else if (!(ft_strncmp(instr, "rra", 4)))
		exec_rr(list_group->stack_a);
	else if (!(ft_strncmp(instr, "rrb", 4)))
		exec_rr(list_group->stack_b);
	else if (!(ft_strncmp(instr, "rrr", 4)))
	{
		exec_rr(list_group->stack_a);
		exec_rr(list_group->stack_b);
	}
}

void	conditional_branch_by_instr1(char *instr, t_list_group *list_group)
{
	if (!(ft_strncmp(instr, "sa", 3)))
		exec_s(list_group->stack_a);
	else if (!(ft_strncmp(instr, "sb", 3)))
		exec_s(list_group->stack_b);
	else if (!(ft_strncmp(instr, "ss", 3)))
	{
		exec_s(list_group->stack_a);
		exec_s(list_group->stack_b);
	}
	else if (!(ft_strncmp(instr, "pa", 3)))
		exec_p(list_group->stack_b, list_group->stack_a);
	else if (!(ft_strncmp(instr, "pb", 3)))
		exec_p(list_group->stack_a, list_group->stack_b);
	else
		conditional_branch_by_instr2(instr, list_group);
}

void	exec_instruction(t_list_group *list_group)
{
	t_instr_list_node	*tmp_instr;

	tmp_instr = list_group->head_instr;
	while (tmp_instr->next != list_group->head_instr)
	{
		conditional_branch_by_instr1(tmp_instr->next->instr, list_group);
		tmp_instr = tmp_instr->next;
	}
}
