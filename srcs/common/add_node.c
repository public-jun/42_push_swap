/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:15:57 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/19 15:57:34 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

t_num_list_node	*make_new_ele(t_list_group *list_group, int value)
{
	t_num_list_node	*res;

	res = (t_num_list_node *)malloc(sizeof(t_num_list_node));
	if (!res)
		ft_put_error_and_exit(list_group);
	res->num = value;
	return (res);
}

int	check_duplicate_value(int value, t_num_list_node *node)
{
	if (value == node->num)
		return (1);
	return (0);
}

t_num_list_node	*get_tail_node(int value, t_num_list_node *stack_a)
{
	t_num_list_node	*tmp;

	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		if (check_duplicate_value(value, tmp->next))
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_node_to_stack(int value, t_list_group *list_group)
{
	t_num_list_node	*tail_node;
	t_num_list_node	*new_node;

	tail_node = get_tail_node(value, list_group->stack_a);
	if (!tail_node)
		ft_put_error_and_exit(list_group);
	new_node = make_new_ele(list_group, value);
	new_node->next = list_group->stack_a;
	new_node->prev = tail_node;
	tail_node->next = new_node;
	list_group->stack_a->prev = new_node;
}
