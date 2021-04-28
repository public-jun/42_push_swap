/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:37:46 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/28 16:1 by4 jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	halve_set(t_info *info, t_list_group *list_group)
{
	t_num_list_node *tmp;

	//all_size のぶんループを回す かつ b が半分になったらやめる
	tmp = list_group->stack_a->next;
	while (info->b_size != info->all_size / 2)
	{
		if (tmp->num < info->all_size / 2)
		{
			tmp = tmp->next;
			exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
			if ( list_group->stack_b->prev->num != 0 && list_group->stack_b->next->num == 0)
				exec_s_r_and_add_instr_node(exec_r, list_group->stack_b, "rb", list_group);
		}
		else
		{
			tmp = tmp->next;
			exec_s_r_and_add_instr_node(exec_r, list_group->stack_a, "ra", list_group);
		}
	}
	exec_s_r_and_add_instr_node(exec_rr, list_group->stack_b, "rrb", list_group);
}

void	sort_over5(t_list_group *list_group, t_info *info)
{
	//pivotより小さいものは b 大きいものは aにpushする
	halve_set(info, list_group);
	/*
	** after half
	*/
	printf("|	stack_a		|	stack_b		|\n");
	t_num_list_node *tmp_a;
	tmp_a = list_group->stack_a->next;
	t_num_list_node *tmp_b;
	tmp_b = list_group->stack_b->next;
	while (tmp_a != list_group->stack_a || tmp_b != list_group->stack_b)
	{
		if (tmp_a != list_group->stack_a)
		{
			printf("|[%d] %*d", tmp_a->num, -10, info->def[tmp_a->num]);
			fflush(stdout);
			tmp_a = tmp_a->next;
		}
		if (tmp_b != list_group->stack_b)
		{
			printf("|[%d] %*d|\n", tmp_b->num, -10, info->def[tmp_b->num]);
			tmp_b = tmp_b->next;
		}
	}
}
