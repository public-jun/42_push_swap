/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:59:18 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 21:38:17 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

t_num_list_node	*free_one_node(t_num_list_node *node)
{
	t_num_list_node	*tmp_prev;

	tmp_prev = node->prev;
	node->next->prev = tmp_prev;
	tmp_prev->next = node->next;
	free(node);
	node = NULL;
	return (tmp_prev->next);
}

t_instr_list_node	*free_one_instr_node(t_instr_list_node *node)
{
	t_instr_list_node	*tmp_prev;

	tmp_prev = node->prev;
	node->next->prev = tmp_prev;
	tmp_prev->next = node->next;
	free(node->instr);
	node->instr = NULL;
	free(node);
	node = NULL;
	return (tmp_prev->next);
}

void	free_stack(t_num_list_node *stack)
{
	t_num_list_node		*tmp;

	if (!stack)
		return ;
	tmp = stack->next;
	while (tmp != stack)
		tmp = free_one_node(tmp);
	free(stack);
}

void	ft_exit(t_list_group *list_group)
{
	t_instr_list_node	*tmp_instr;

	free_stack(list_group->stack_a);
	free_stack(list_group->stack_b);
	free_stack(list_group->stack_a_test);
	free_stack(list_group->stack_b_test);
	tmp_instr = list_group->head_instr->next;
	while (tmp_instr != list_group->head_instr)
		tmp_instr = free_one_instr_node(tmp_instr);
	free(list_group->head_instr->instr);
	free(list_group->head_instr);
	exit(0);
}

void	ft_put_error_and_exit(t_list_group *list_group)
{
	write(2, "Error\n", 6);
	ft_exit(list_group);
}
