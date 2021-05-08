/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:48:59 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 14:59:50 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_num_list_node **tmp, t_num_list_node *head, t_info *info)
{
	if (*tmp != head)
	{
		print_one_node((*tmp)->num, info->def[(*tmp)->num]);
		ft_putchar_fd('|', 1);
		*tmp = (*tmp)->next;
	}
	else
		ft_putstr_fd("                   |", 1);
}

static void	sort_visual(t_instr_list_node *tmp_instr,
t_list_group *list_group, t_info *info)
{
	int				flag;
	int				loop_count;
	t_num_list_node	*tmp_a;
	t_num_list_node	*tmp_b;

	loop_count = 0 ;
	flag = 0;
	tmp_a = list_group->stack_a_test->next;
	tmp_b = list_group->stack_b_test->next;
	while (loop_count++ < 40)
	{
		ft_putchar_fd('|', 1);
		print_stack(&tmp_a, list_group->stack_a_test, info);
		print_stack(&tmp_b, list_group->stack_b_test, info);
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
	t_instr_list_node	*tmp_instr;
	int					j;

	ft_putstr_fd(CLEAR, 1);
	tmp_instr = list_group->head_instr->next;
	while (tmp_instr != list_group->head_instr)
	{
		ft_putstr_fd(CLEAR, 1);
		ft_putstr_fd("|      stack_a      ", 1);
		ft_putstr_fd("|      stack_b      ", 1);
		ft_putstr_fd("|      next      |\n", 1);
		sort_visual(tmp_instr, list_group, info);
		j = 0;
		while (j++ < (1000000000 / 6))
			;
		conditional_branch_by_instr1(list_group->stack_a_test,
			list_group->stack_b_test, tmp_instr->instr);
		tmp_instr = tmp_instr->next;
	}
	ft_putstr_fd(CLEAR, 1);
	ft_putstr_fd("|      stack_a      ", 1);
	ft_putstr_fd("|      stack_b      ", 1);
	ft_putstr_fd("|      next      |\n", 1);
	sort_visual(tmp_instr, list_group, info);
}

void	exe_option(t_list_group *list_group, t_info *info)
{
	if (info->v_flag)
		option_v(list_group, info);
	if (info->a_flag)
		print_sort_result1(list_group, info);
}
