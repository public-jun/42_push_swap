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

void	exec_swap_rotate_and_add_instr_node(void (*f)(t_num_list_node *), t_num_list_node *stack,char *instr, t_list_group *list_group)
{
	f(stack);
	add_node_to_instr_list(instr, list_group);
}

void	exec_push_and_add_instr_node(t_num_list_node *from, t_num_list_node *to, t_list_group *list_group, char *instr)
{
	exec_push(from, to);
	add_node_to_instr_list(instr, list_group);
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
	{
		if (stack == list_group->stack_a)
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sa", list_group)
		else
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sb", list_group)
	}
	//3, 2, 1
	else if (first > second && second > third && first > third)
	{
		if (stack == list_group->stack_a)
		{
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sa", list_group);
			exec_swap_rotate_and_add_instr_node(exec_reverse_rotate, stack, "rra", list_group);
		}
		else
		{
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sb", list_group);
			exec_swap_rotate_and_add_instr_node(exec_reverse_rotate, stack, "rrb", list_group);
		}
	}
	//3, 1, 2
	else if (first > second && second < third && first > third)
	{
		if (stack == list_group->stack_a)
			exec_swap_rotate_and_add_instr_node(exec_rotate, stack, "ra", list_group);
		else
			exec_swap_rotate_and_add_instr_node(exec_rotate, stack, "rb", list_group);
	}
	//1, 3, 2
	else if (first < second && second > third && first < third)
	{
		if (stack == list_group->stack_a)
		{
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sa", list_group);
			exec_swap_rotate_and_add_instr_node(exec_rotate, stack, "ra", list_group);
		}
		else
		{
			exec_swap_rotate_and_add_instr_node(exec_swap, stack, "sb", list_group);
			exec_swap_rotate_and_add_instr_node(exec_rotate, stack, "rb", list_group);
		}
	}
	//2, 3, 1
	else if (first < second && second > third && first > third)
	{
		if (stack == list_group->stack_a)
			exec_swap_rotate_and_add_instr_node(exec_reverse_rotate, stack, "rra", list_group);
		else
			exec_swap_rotate_and_add_instr_node(exec_reverse_rotate, stack, "rrb", list_group);
	}
}


void	sort_less6(t_list_group *list_group, int size)
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
			exec_swap_rotate_and_add_instr_node(exec_swap, stack_a, "sa", list_group);
	}
	//引数が3
	else if (size == 3)
		sort_only_three(stack_a, list_group);
	else if (size <= 5 )
		while (size > 3)
		{

		}
}

void	add_value_to_pair(t_info *info, int value, int i)
{
	info->n[i].value = value;
	info->n[i].id = i;
}

void	convert_val_to_id(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->n_size)
	{
		info->def[i] = info->n[i].value;
		info->n[i].value = i;
		i++;
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
		add_node_to_stack(value, &list_group);
		add_value_to_pair(&info, value, i - 1);
		i++;
	}
	info.n_size = ac - 1;
	// int j = 0;
	// printf("after add_value\n");
	// printf("[id] value\n");
	// while (j < info.n_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	quick_sort(info.n, 0, info.n_size - 1, SORT_VALUE);
	// j = 0;
	// printf("after quick_sort_value\n");
	// printf("[id] value\n");
	// while (j < info.n_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	convert_val_to_id(&info);
	// j = 0;
	// printf("after convert_value_to_id\n");
	// printf("[id] value\n");
	// while (j < info.n_size)
	// {
	// 	printf("[%d] %d\n", info.n[j].id, info.n[j].value);
	// 	j++;
	// }
	quick_sort(info.n, 0, info.n_size - 1, SORT_ID);
	//引数が5以下
	// if (ac - 1 < 6)
	// 	sort_less6(&list_group, ac - 1);
	// else
	// 	sort_over5()
	//引数が6個以上

	// printf("after quick_sort_id\n");
	// printf("[id] value\n");
	//[value] def
	// j = 0;
	// while (j < info.n_size)
	// {
	// 	printf("[%d] %d -> %d\n", info.n[j].id, info.n[j].value, info.def[info.n[j].value]);
	// 	j++;
	// }

	return (0);
}
