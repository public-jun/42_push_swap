/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_by_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:36:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 21:58:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	conditional_branch_by_instr2(t_num_list_node *a, t_num_list_node *b, char *instr)
{
	if (!(ft_strncmp(instr, "ra", 3)))
		exec_r(a);
	else if (!(ft_strncmp(instr, "rb", 3)))
		exec_r(b);
	else if (!(ft_strncmp(instr, "rr", 3)))
	{
		exec_r(a);
		exec_r(b);
	}
	else if (!(ft_strncmp(instr, "rra", 4)))
		exec_rr(a);
	else if (!(ft_strncmp(instr, "rrb", 4)))
		exec_rr(b);
	else if (!(ft_strncmp(instr, "rrr", 4)))
	{
		exec_rr(a);
		exec_rr(b);
	}
}

void	conditional_branch_by_instr1(t_num_list_node *a, t_num_list_node *b, char *instr)
{
	if (!(ft_strncmp(instr, "sa", 3)))
		exec_s(a);
	else if (!(ft_strncmp(instr, "sb", 3)))
		exec_s(b);
	else if (!(ft_strncmp(instr, "ss", 3)))
	{
		exec_s(a);
		exec_s(b);
	}
	else if (!(ft_strncmp(instr, "pa", 3)))
		exec_p(b, a);
	else if (!(ft_strncmp(instr, "pb", 3)))
		exec_p(a, b);
	else
		conditional_branch_by_instr2(a, b, instr);
}

void	exec_instruction(t_list_group *list_group)
{
	t_instr_list_node	*tmp_instr;

	tmp_instr = list_group->head_instr;
	while (tmp_instr->next != list_group->head_instr)
	{
		conditional_branch_by_instr1(list_group->stack_a, list_group->stack_b, tmp_instr->next->instr);
		tmp_instr = tmp_instr->next;
	}
}
