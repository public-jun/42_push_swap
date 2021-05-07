/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:52:47 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 22:24:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec_s_r_and_add_instr_node(void (*f)(t_num_list_node *),
	t_num_list_node *stack, char *instr, t_list_group *list_group, t_info *info)
{
	int		pivot;

	pivot = info->p_head->next->p_value;
	if (!ft_strncmp(instr, "ra", 3)
		&& list_group->stack_a->next->num == info->want)
	{
		if (pivot == info->want)
			free_one_pivot_node(info->p_head->next);
		info->want++;
	}
	f(stack);
	add_node_to_instr_list(instr, list_group);
}

void	exec_p_and_add_instr_node(t_num_list_node *from,
	t_num_list_node *to, t_list_group *list_group, t_info *info)
{
	exec_p(from, to);
	if (from == list_group->stack_a)
	{
		add_node_to_instr_list("pb", list_group);
		info->a_size--;
		info->b_size++;
	}
	else
	{
		add_node_to_instr_list("pa", list_group);
		info->b_size--;
		info->a_size++;
	}
}
