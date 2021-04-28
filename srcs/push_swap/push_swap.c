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

// //sortしたら命令をlistに格納する

void	exec_s_r_and_add_instr_node(void (*f)(t_num_list_node *), t_num_list_node *stack,char *instr, t_list_group *list_group)
{
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


void	sort_only_three(t_num_list_node *stack, t_list_group *list_group)
{
	int	first;
	int	second;
	int	third;

	first = stack->next->num;
	second = stack->next->next->num;
	third = stack->next->next->next->num;
	//2, 1, 3
	if (first > second && second < third && first < third)
		sort_only_three_case1(stack, list_group);
	//3, 2, 1
	else if (first > second && second > third && first > third)
		sort_only_three_case2(stack, list_group);
	//3, 1, 2
	else if (first > second && second < third && first > third)
		sort_only_three_case3(stack, list_group);
	//1, 3, 2
	else if (first < second && second > third && first < third)
		sort_only_three_case4(stack, list_group);
	//2, 3, 1
	else if (first < second && second > third && first > third)
		sort_only_three_case5(stack, list_group);
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

void	min_move_top(t_num_list_node *stack, int min, t_info *info, t_list_group *list_group)
{
	int pivot;
	int	tmp;

	pivot = (info->a_size) / 2;
	tmp = min;
	//半分よりinfo->n[i].id が小さい
	if (min <= pivot)
	{
		while (tmp-- > 0)
			exec_s_r_and_add_instr_node(exec_r, stack, "ra", list_group);

	}
	else
	{
		while (tmp++ < info->a_size)
			exec_s_r_and_add_instr_node(exec_rr, stack, "rra", list_group);
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
		min_move_top(stack, min, info, list_group);
		//stackの中が3個になるまでpushする
		exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
	}
	sort_only_three(stack, list_group);
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
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa", list_group);
	}
	//引数が3
	else if (size == 3)
		sort_only_three(stack_a, list_group);
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
	//引数が5以下
	no_sort(&list_group, &info);
	if (ac - 1 < 6)
		sort_less6(&info, &list_group, ac - 1);
	//引数が6個以上
	else
		sort_over5(&list_group, &info);

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

	t_num_list_node *p = list_group.stack_a;
	printf("\n---result-----\n");
	while (p->next != list_group.stack_a)
	{
		printf("%d\n", info.def[p->next->num]);
		p = p->next;
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
	ft_exit(&list_group);
	return (0);
}
