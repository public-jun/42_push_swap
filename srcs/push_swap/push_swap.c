/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:18 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/24 23:07:38by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#define  ESC 0x1b

// //sortしたら命令をlistに格納する

void	exec_s_r_and_add_instr_node(void (*f)(t_num_list_node *), t_num_list_node *stack,char *instr, t_list_group *list_group, t_info *info)
{
	int		pivot;

	pivot = info->p_head->next->p_value;
	if (!ft_strncmp(instr, "ra", 3) && list_group->stack_a->next->num == info->want)
	{
		//pivotをsortする場合はpivot_listから削除する
		if (pivot == info->want)
			free_one_pivot_node(info->p_head->next);
		info->want++;
	}
	f(stack);
	add_node_to_instr_list(instr, list_group);
}

void	exec_p_and_add_instr_node(t_num_list_node *from, t_num_list_node *to, char *instr, t_list_group *list_group, t_info *info)
{
	exec_p(from, to);
	add_node_to_instr_list(instr, list_group);
	if (from == list_group->stack_a)
	{
		info->a_size--;
		info->b_size++;
	}
	else
	{
		info->b_size--;
		info->a_size++;
	}
}


void	sort_only_three(t_num_list_node *stack, t_list_group *list_group, t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = stack->next->num;
	second = stack->next->next->num;
	third = stack->next->next->next->num;
	//2, 1, 3
	if (first > second && second < third && first < third)
		sort_only_three_case1(stack, list_group, info);
	//3, 2, 1
	else if (first > second && second > third && first > third)
		sort_only_three_case2(stack, list_group, info);
	//3, 1, 2
	else if (first > second && second < third && first > third)
		sort_only_three_case3(stack, list_group, info);
	//1, 3, 2
	else if (first < second && second > third && first < third)
		sort_only_three_case4(stack, list_group, info);
	//2, 3, 1
	else if (first < second && second > third && first > third)
		sort_only_three_case5(stack, list_group, info);
}

int		count_size(t_num_list_node *stack)
{
	t_num_list_node *tmp;
	int	res;

	res = 0;
	tmp = stack->next;
	while (tmp != stack)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

int		find_min_value(t_num_list_node *head)
{
	t_num_list_node *tmp;
	t_num_list_node *min;
	int				res;
	int				i;

	tmp = head->next;
	min = tmp;
	res = 0;
	i = 0;
	while (tmp != head)
	{
		if (tmp->num < min->num)
		{
			res = i;
			min = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (res);
}

void	min_move_top(t_num_list_node *stack, int min, t_info *info, t_list_group *list_group, int size)
{
	int pivot;
	int	tmp;

	pivot = size / 2;
	tmp = min;
	//半分よりinfo->n[i].id が小さい
	if (min <= pivot)
	{
		while (tmp-- > 0)
			exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group, info);

	}
	else
	{
		while (tmp++ < size)
			exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group, info);
	}
}

void	pb_all_node(t_list_group *list_group, t_info *info)
{
	t_num_list_node *tmp;
	tmp = list_group->stack_b->next;
	while (tmp != list_group->stack_b)
	{
		tmp = tmp->next;
		exec_p_and_add_instr_node(list_group->stack_b, list_group->stack_a, "pa", list_group, info);
	}
}


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

void	sort_less6(t_info *info, t_list_group *list_group, int size)
{
	t_num_list_node *stack_a;

	stack_a = list_group->stack_a;
	//引数が1
	if (size == 1)
		ft_exit(list_group);
	//引数が2
	else if (size == 2)
	{
		if (stack_a->next->num > stack_a->next->next->num)
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa", list_group, info);
	}
	//引数が3
	else if (size == 3)
		sort_only_three(stack_a, list_group, info);
	//引数が 5以下
	else if (size <= 5 )
		sort_more_four_less_six(stack_a, list_group, info);
}

void	add_value_to_pair(t_info *info, int value, int i, t_list_group *list_group)
{
	int j;

	if (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (value == info->n[j].value)
				ft_put_error_and_exit(list_group);
			j++;
		}
	}
	info->n[i].value = value;
	info->n[i].id = i;
}

void	convert_val_to_id(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->all_size)
	{
		info->def[i] = info->n[i].value;
		info->n[i].value = i;
		i++;
	}
}

void	make_stack_num_is_id(t_info *info, t_list_group *list_group)
{
	int		i;

	i = 0;
	while (i < info->all_size)
	{
		add_node_to_stack(info->n[i].value, list_group);
		i++;
	}
}

void	no_sort(t_list_group *list_group, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->all_size - 1)
	{
		if (info->n[i].value + 1 != info->n[i + 1].value)
			return ;
		i++;
	}
	ft_exit(list_group);

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


void	test(t_list_group *list_group, t_info *info)
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
}

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_list_group	list_group;
	t_info	info;

	init_list(&list_group);
	i = 1;
	if (ac == 1)
		ft_exit(&list_group);
	while (i < ac)
	{
		value = get_valid_num(av[i], &list_group);
		// add_node_to_stack(value, &list_group);
		add_value_to_pair(&info, value, i - 1, &list_group);
		i++;
	}
	info.all_size = ac - 1;
	info.a_size = info.all_size;
	info.b_size = 0;
	info.want = 0;
	// int j = 0;
	// printf("after add_value\n");
	// printf("[id] value\n");
	// while (j < info.all_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	quick_sort(info.n, 0, info.all_size - 1, SORT_VALUE);
	// j = 0;
	// printf("after quick_sort_value\n");
	// printf("[id] value\n");
	// while (j < info.all_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	convert_val_to_id(&info);
	// j = 0;
	// printf("after convert_value_to_id\n");
	// printf("[id] value\n");
	// while (j < info.all_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	quick_sort(info.n, 0, info.all_size - 1, SORT_ID);
	//n のvalue を list化
	make_stack_num_is_id(&info, &list_group);
	//stack_a をコピーする
	copy_stack_a(&list_group);
	//引数が5以下
	no_sort(&list_group, &info);
	if (ac - 1 < 6)
		sort_less6(&info, &list_group, ac - 1);
	//引数が6個以上
	else
		sort_over5(&list_group, &info);

	//最適化
	instr_optimization(&list_group);

	//info.def[list_group.stack_a->next->num]
	// printf("after quick_sort_id\n");
	// printf("[id] value\n");
	//[value] def
	// j = 0;
	// while (j < info.all_size)
	// {
	// 	printf("[%d] %d -> %d\n", info.n[j].id, info.n[j].value, info.def[info.n[j].value]);
	// 	j++;
	// }

	// t_num_list_node *p = list_group.stack_a;
	// printf("\n---result-----\n");
	// while (p->next != list_group.stack_a)
	// {
	// 	printf("%d\n", info.def[p->next->num]);
	// 	p = p->next;
	// }

	//instruction を test_stack に実行する
	test(&list_group, &info);
	t_num_list_node *tmp_a;
	t_num_list_node *tmp_b;
	tmp_a = list_group.stack_a->next;
	tmp_b = list_group.stack_b->next;
	printf("\n\n-----after_sort------\n");
	while (tmp_a != list_group.stack_a || tmp_b != list_group.stack_b)
	{
		if (tmp_a != list_group.stack_a)
		{
			printf("|[%d] %*d", tmp_a->num, -10, info.def[tmp_a->num]);
			fflush(stdout);
			tmp_a = tmp_a->next;
		}
		printf("|");
		if (tmp_b != list_group.stack_b)
		{
			printf("[%d] %*d|", tmp_b->num, -10, info.def[tmp_b->num]);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	printf("\n---instr_list-----\n");
	t_instr_list_node *instr_p = list_group.head_instr;
	int instr_count = 0;
	while (instr_p->next != list_group.head_instr)
	{
		printf("%s\n", instr_p->next->instr);
		instr_p = instr_p->next;
		instr_count++;
	}
	printf("instr_count : %d\n", instr_count);
	ft_info_free(&info);
	ft_exit(&list_group);
	return (0);
}
