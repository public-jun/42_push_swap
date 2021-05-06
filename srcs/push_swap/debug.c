/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:25:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/06 14:09:45 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_sort_result(t_list_group *list_group, t_info *info)
{
	t_num_list_node *tmp_a;
	t_num_list_node *tmp_b;

	tmp_a = list_group->stack_a->next;
	tmp_b = list_group->stack_b->next;
	printf("\n\n-----after_sort------\n");
	while (tmp_a != list_group->stack_a || tmp_b != list_group->stack_b)
	{
		if (tmp_a != list_group->stack_a)
		{
			printf("|[%d] %*d", tmp_a->num, -10, info->def[tmp_a->num]);
			fflush(stdout);
			tmp_a = tmp_a->next;
		}
		printf("|");
		if (tmp_b != list_group->stack_b)
		{
			printf("[%d] %*d|", tmp_b->num, -10, info->def[tmp_b->num]);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
}
void	copy_stack_a(t_list_group *group)
{
	t_num_list_node *tmp;
	t_num_list_node *new_node;

	group->stack_a_test = make_new_ele(group, -1);
	group->stack_b_test = make_new_ele(group, -1);
	group->stack_a_test->prev = group->stack_a_test;
	group->stack_a_test->next = group->stack_a_test;
	group->stack_b_test->prev = group->stack_b_test;
	group->stack_b_test->next = group->stack_b_test;

	tmp = group->stack_a->next;
	int		value;
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

void	option_v(t_list_group *list_group, t_info *info)
{
	int	loop;
	t_num_list_node *a;
	t_num_list_node *b;
	t_num_list_node *tmp_a;
	t_num_list_node *tmp_b;
	t_instr_list_node *tmp_instr;
	char *instr;
	int	flag;
	printf("%c[2J", ESC);

	loop = 0;
	a = list_group->stack_a_test;
	b = list_group->stack_b_test;
	tmp_instr = list_group->head_instr->next;
	while (tmp_instr != list_group->head_instr)
	{
		printf("%c[2J", ESC);
		printf("|%*s    |%*s    |%*s    |\n", 10, "stack_a", 10, "stack_b", 10, "next");
		tmp_a = a->next;
		tmp_b = b->next;
		flag = 0;
		int loop_count;
		loop_count = 0 ;
		while ((tmp_a != a || tmp_b != b) && loop_count < 40)
		{
			if (tmp_a != a)
			{
				printf("|[%*d] %*d", 4, tmp_a->num, -10, info->def[tmp_a->num]);
				fflush(stdout);
				tmp_a = tmp_a->next;
			}
			printf("|");
			if (tmp_b != b)
			{
				printf("[%*d] %*d|", 4, tmp_b->num, -10, info->def[tmp_b->num]);
				tmp_b = tmp_b->next;
			}
			if (tmp_instr != list_group->head_instr && flag == 0)
			{
				printf("%s |", tmp_instr->instr);
				flag = 1;
			}
			printf("\n");
			loop_count++;
		}
		//instruction 実行
	// for (int j = 0; j < (1000000000 / 100); j++) {}
	instr = tmp_instr->instr;
	if (!(ft_strncmp(instr, "sa", 3)))
		exec_s(a);
	else if (!(ft_strncmp(instr, "sb", 3)))
		exec_s(b);
	else if (!(ft_strncmp(instr, "ss", 3)))
	{
		exec_s(a);
		exec_s(b);
	}
	else if (!(ft_strncmp(instr, "pa", 3)))
		exec_p(b, a);
	else if (!(ft_strncmp(instr, "pb", 3)))
		exec_p(a, b);
	else if (!(ft_strncmp(instr, "ra", 3)))
		exec_r(a);
	else if (!(ft_strncmp(instr, "rb", 3)))
		exec_r(b);
	else if (!(ft_strncmp(instr, "rr", 3)))
	{
		exec_r(a);
		exec_r(b);
	}
	else if (!(ft_strncmp(instr, "rra", 4)))
		exec_rr(a);
	else if (!(ft_strncmp(instr, "rrb", 4)))
		exec_rr(b);
	else if (!(ft_strncmp(instr, "rrr", 4)))
	{
		exec_rr(a);
		exec_rr(b);
	}
	tmp_instr = tmp_instr->next;
	}
	print_sort_result(list_group, info);
}
