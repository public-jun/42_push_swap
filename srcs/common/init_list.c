/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:12:51 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 18:11:48 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_instr_list(t_list_group *list_group)
{
	list_group->head_instr = make_new_instr_node(list_group, NULL);
	list_group->head_instr->prev = list_group->head_instr;
	list_group->head_instr->next = list_group->head_instr;
}

void	init_list(t_list_group *list_group)
{
	list_group->stack_a = make_new_ele(list_group, 0);
	list_group->stack_b = make_new_ele(list_group, 0);
	list_group->stack_a->prev = list_group->stack_a;
	list_group->stack_a->next = list_group->stack_a;
	list_group->stack_b->prev = list_group->stack_b;
	list_group->stack_b->next = list_group->stack_b;
	init_instr_list(list_group);
}
