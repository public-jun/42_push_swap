/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:37:56 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 11:34:47 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_put_KO_and_exit(t_list_group *list_group)
{
	write(1, "KO\n", 3);
	ft_exit(list_group);
}

void	ft_put_OK_and_exit(t_list_group *list_group)
{
	write(1, "OK\n", 3);
	ft_exit(list_group);
}

void	is_stack_b_no_node(t_list_group *list_group)
{
	if ((list_group->stack_b->next == list_group->stack_b)
		&& (list_group->stack_b->prev == list_group->stack_b))
		return ;
	ft_put_KO_and_exit(list_group);
}


void	check_list_order(t_list_group *list_group)
{
	t_num_list_node	*tmp_stack_a;
	t_num_list_node	*next_stack_a;

	is_stack_b_no_node(list_group);
	tmp_stack_a = list_group->stack_a->next;
	next_stack_a = list_group->stack_a->next->next;
	while (next_stack_a != list_group->stack_a)
	{
		if (tmp_stack_a->num > next_stack_a->num)
			ft_put_KO_and_exit(list_group);
		tmp_stack_a = tmp_stack_a->next;
		next_stack_a = next_stack_a->next;
	}
	ft_put_OK_and_exit(list_group);
}
