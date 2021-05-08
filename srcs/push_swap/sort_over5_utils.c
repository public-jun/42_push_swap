/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:43:57 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 17:58:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_pivot	*make_new_pivot(t_list_group *list_group, t_info *info, int pivot)
{
	t_pivot	*res;

	res = (t_pivot *)malloc(sizeof(t_pivot));
	if (!res)
		ft_put_error_and_ps_exit(list_group, info);
	res->p_value = pivot;
	return (res);
}

void	add_front_pivot_list(int pivot, t_list_group *list_group, t_info *info)
{
	t_pivot		*new_node;
	t_pivot		*head;

	head = info->p_head;
	new_node = make_new_pivot(list_group, info, pivot);
	new_node->next = head->next;
	new_node->prev = head;
	head->next->prev = new_node;
	head->next = new_node;
}

void	operation_serch_want(t_num_list_node *stack_a, t_num_list_node *stack_b,
	t_list_group *list_group, t_info *info)
{
	if (stack_a->next->num == info->want)
		exec_s_r_and_add_instr_node(exec_r,
			stack_a, "ra", list_group, info);
	else if (stack_b->next->num == info->want)
		exec_p_and_add_instr_node(stack_b,
			stack_a, list_group, info);
	else if (stack_b->next->next->num == info->want)
		exec_s_r_and_add_instr_node(exec_s,
			stack_b, "sb", list_group, info);
	else if (stack_b->prev->num == info->want)
		exec_s_r_and_add_instr_node(exec_rr,
			stack_b, "rrb", list_group, info);
	else if (stack_a->next->next->num == info->want)
		exec_s_r_and_add_instr_node(exec_s,
			stack_a, "sa", list_group, info);
}

void	serch_want(t_list_group *list_group, t_info *info)
{
	t_num_list_node	*stack_a;
	t_num_list_node	*stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	while ((stack_a->next->num == info->want
			|| stack_a->next->next->num == info->want
			|| stack_b->next->num == info->want
			|| stack_b->next->next->num == info->want
			|| stack_b->prev->num == info->want)
		&& info->want != info->all_size)
		operation_serch_want(stack_a, stack_b, list_group, info);
}

int	count_pivot_node(t_info *info)
{
	t_pivot	*tmp;
	int		count;

	tmp = info->p_head->next;
	count = 0;
	while (tmp != info->p_head)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
