/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:36:07 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 16:36:15 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.h"
#include "../includes/common.h"

//type s*
void	exec_swap(t_num_list_node *stack)
{
	t_num_list_node *first;
	t_num_list_node *second;

	first = stack->next;
	second = first->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = stack;
	stack->next = second;
}

//type r*
void	exec_rotate(t_num_list_node *stack)
{
	t_num_list_node	*first;

	first = stack->next;
	stack->next = first->next;
	first->next->prev = stack;
	stack->prev->next = first;
	first->prev = stack->prev;
	stack->prev = first;
	first->next = stack;
}

//type rr*
void	exec_reverse_rotate(t_num_list_node *stack)
{
	t_num_list_node	*last;

	last = stack->prev;
	stack->prev = last->prev;
	last->prev->next = stack;
	stack->next->prev = last;
	last->next = stack->next;
	stack->next = last;
	last->prev = stack;
}

//type p*
void	exec_push(t_num_list_node *from, t_num_list_node *to)
{
	t_num_list_node *tmp;

	tmp = from->next;
	from->next = tmp->next;
	tmp->next->prev = from;
	to->next->prev = tmp;
	tmp->next = to->next;
	to->next = tmp;
	tmp->prev = to;
}

void	conditional_branch_by_instr(char *instr, t_list_group *list_group)
{
	if (!(ft_strncmp(instr, "sa", 3)))
		exec_swap(list_group->stack_a);
	else if (!(ft_strncmp(instr, "sb", 3)))
		exec_swap(list_group->stack_b);
	else if (!(ft_strncmp(instr, "ss", 3)))
	{
		exec_swap(list_group->stack_a);
		exec_swap(list_group->stack_b);
	}
	else if (!(ft_strncmp(instr, "pa", 3)))
		exec_push(list_group->stack_b, list_group->stack_a);
	else if (!(ft_strncmp(instr, "pb", 3)))
		exec_push(list_group->stack_a, list_group->stack_b);
	else if (!(ft_strncmp(instr, "ra", 3)))
		exec_rotate(list_group->stack_a);
	else if (!(ft_strncmp(instr, "rb", 3)))
		exec_rotate(list_group->stack_b);
	else if (!(ft_strncmp(instr, "rr", 3)))
	{
		exec_rotate(list_group->stack_a);
		exec_rotate(list_group->stack_b);
	}
	else if (!(ft_strncmp(instr, "rra", 4)))
		exec_reverse_rotate(list_group->stack_a);
	else if (!(ft_strncmp(instr, "rrb", 4)))
		exec_reverse_rotate(list_group->stack_b);
	else if (!(ft_strncmp(instr, "rrr", 4)))
	{
		exec_reverse_rotate(list_group->stack_a);
		exec_reverse_rotate(list_group->stack_b);
	}
}


void	exec_instruction(t_list_group *list_group)
{
	t_instr_list_node	*tmp_instr;

	tmp_instr = list_group->head_instr;
	while (tmp_instr->next != list_group->head_instr)
	{
		conditional_branch_by_instr(tmp_instr->next->instr, list_group);
		tmp_instr = tmp_instr->next;
	}
}
