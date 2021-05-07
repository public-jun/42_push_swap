/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:19:53 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 16:21:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

//type s*
void	exec_s(t_num_list_node *stack)
{
	t_num_list_node	*first;
	t_num_list_node	*second;

	first = stack->next;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = stack;
	stack->next = second;
}

//type r*
void	exec_r(t_num_list_node *stack)
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
void	exec_rr(t_num_list_node *stack)
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
void	exec_p(t_num_list_node *from, t_num_list_node *to)
{
	t_num_list_node	*tmp;

	tmp = from->next;
	from->next = tmp->next;
	tmp->next->prev = from;
	to->next->prev = tmp;
	tmp->next = to->next;
	to->next = tmp;
	tmp->prev = to;
}
