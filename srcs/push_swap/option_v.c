/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:48:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 22:03:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_visual(t_num_list_node *tmp_a, t_num_list_node *tmp_b,t_instr_list_node *tmp_instr, t_list_group *list_group, t_info *info)
{
	int	flag;
	int loop_count;

	loop_count = 0 ;
	flag = 0;
	while ((tmp_a != list_group->stack_a_test || tmp_b != list_group->stack_b_test) && loop_count++ < 40)
	{
		ft_putchar_fd('|', 1);
		if (tmp_a != list_group->stack_a_test)
		{
			print_one_node(tmp_a->num, info->def[tmp_a->num]);
			tmp_a = tmp_a->next;
		}
		ft_putchar_fd('|', 1);
		if (tmp_b != list_group->stack_b_test)
		{
			print_one_node(tmp_b->num, info->def[tmp_b->num]);
			ft_putchar_fd('|', 1);
			tmp_b = tmp_b->next;
		}
		if (tmp_instr != list_group->head_instr && flag++ == 0)
		{
			ft_putstr_fd(tmp_instr->instr, 1);
			ft_putstr_fd("              |", 1);
		}
		ft_putchar_fd('\n', 1);
	}
}

void	option_v(t_list_group *list_group, t_info *info)
{
	t_num_list_node *tmp_a;
	t_num_list_node *tmp_b;
	t_instr_list_node *tmp_instr;

	ft_putstr_fd(CLEAR, 1);
	tmp_instr = list_group->head_instr->next;
	while (tmp_instr != list_group->head_instr)
	{
		ft_putstr_fd(CLEAR, 1);
		ft_putstr_fd("|      stack_a      |      stack_b      |      next      |\n", 1);
		tmp_a = list_group->stack_a_test->next;
		tmp_b = list_group->stack_b_test->next;
		sort_visual(tmp_a, tmp_b, tmp_instr, list_group, info);
		for (int j = 0; j < (1000000000 / 100); j++) {}
		conditional_branch_by_instr1(list_group->stack_a_test, list_group->stack_b_test, tmp_instr->instr);
		tmp_instr = tmp_instr->next;
	}
	print_sort_result1(list_group, info);
}
