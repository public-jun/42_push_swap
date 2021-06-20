/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:25:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/20 21:26:55 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_space_num(int s_size, int num, int left_flag)
{
	int	digits;

	digits = count_digits(num);
	if (left_flag)
		ft_putnbr_fd(num, 1);
	while (digits < s_size)
	{
		ft_putchar_fd(' ', 1);
		digits++;
	}
	if (!left_flag)
		ft_putnbr_fd(num, 1);
}

void	print_one_node(int id, int num)
{
	ft_putchar_fd('[', 1);
	print_space_num(3, id, 0);
	ft_putstr_fd("] ", 1);
	print_space_num(13, num, 1);
}

void	print_sort_result2(t_num_list_node *tmp_a,
	t_num_list_node *tmp_b, t_list_group *list_group, t_info *info)
{
	while (tmp_a != list_group->stack_a || tmp_b != list_group->stack_b)
	{
		ft_putchar_fd('|', 1);
		if (tmp_a != list_group->stack_a)
		{
			print_one_node(tmp_a->num, info->def[tmp_a->num]);
			tmp_a = tmp_a->next;
		}
		ft_putchar_fd('|', 1);
		if (tmp_b != list_group->stack_b)
		{
			print_one_node(tmp_b->num, info->def[tmp_b->num]);
			ft_putchar_fd('|', 1);
			tmp_b = tmp_b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}

void	print_sort_result1(t_list_group *list_group, t_info *info)
{
	t_num_list_node	*tmp_a;
	t_num_list_node	*tmp_b;

	tmp_a = list_group->stack_a->next;
	tmp_b = list_group->stack_b->next;
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("\n\n-----after_sort------\n", 1);
	ft_putstr_fd(DEFCOLOR, 1);
	ft_putstr_fd("|      stack_a      |      stack_b      |\n", 1);
	print_sort_result2(tmp_a, tmp_b, list_group, info);
}

void	copy_stack_a(t_list_group *group)
{
	t_num_list_node		*tmp;
	t_num_list_node		*new_node;
	int					value;

	group->stack_a_test = make_new_ele(group, -1);
	group->stack_b_test = make_new_ele(group, -1);
	group->stack_a_test->prev = group->stack_a_test;
	group->stack_a_test->next = group->stack_a_test;
	group->stack_b_test->prev = group->stack_b_test;
	group->stack_b_test->next = group->stack_b_test;
	tmp = group->stack_a->next;
	while (tmp != group->stack_a)
	{
		value = tmp->num;
		new_node = make_new_ele(group, value);
		new_node->prev = group->stack_a_test->prev;
		new_node->next = group->stack_a_test;
		group->stack_a_test->prev->next = new_node;
		group->stack_a_test->prev = new_node;
		tmp = tmp->next;
	}
}
