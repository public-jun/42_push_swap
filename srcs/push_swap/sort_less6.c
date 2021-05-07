/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:05:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 10:19:50 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_more_four_less_six(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	int	min;

	while (info->a_size != 3)
	{
		//stack の中から最小値を見つける
		min = find_min_value(stack);
		//一番上に持ってくる
		min_move_top(stack, min, info, list_group, info->a_size);
		//stackの中が3個になるまでpushする
		exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
	}
	sort_only_three(stack, list_group, info);
	//stack_b から全てpush
	pb_all_node(list_group, info);
}

void	sort_less6(t_info *info, t_list_group *list_group)
{
	t_num_list_node *stack_a;

	stack_a = list_group->stack_a;
	//引数が1
	if (info->all_size == 1)
		ft_exit(list_group);
	//引数が2
	else if (info->all_size == 2)
	{
		if (stack_a->next->num > stack_a->next->next->num)
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa", list_group, info);
	}
	//引数が3
	else if (info->all_size == 3)
		sort_only_three(stack_a, list_group, info);
	//引数が 5以下
	else if (info->all_size <= 5 )
		sort_more_four_less_six(stack_a, list_group, info);
}
