/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/16 16:58:53 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_num_list_node *free_one_node(t_num_list_node *node)
{
	t_num_list_node *tmp_prev;

	tmp_prev = node->prev;
	node->next->prev = tmp_prev;
	tmp_prev->next = node->next;
	free(node);
	node = NULL;
	return (tmp_prev->next);
}

void	ft_exit(t_stack_group *stack_group)
{
	t_num_list_node *tmp;

	tmp = stack_group->head_a->next;
	while (tmp != stack_group->head_a)
		tmp = free_one_node(tmp);
	free(stack_group->head_a);
	stack_group->head_a = NULL;
	tmp = stack_group->head_b->next;
	while (tmp != stack_group->head_b)
		tmp = free_one_node(tmp);
	free(stack_group->head_b);
	stack_group->head_b = NULL;
	exit(0);
}

void	ft_put_error_and_exit(t_stack_group *stack_group)
{
	write(2, "Error\n", 6);
	ft_exit(stack_group);
}

t_num_list_node *make_new_ele(t_stack_group *stack_group, int value)
{
	t_num_list_node *res;

	res = (t_num_list_node*)malloc(sizeof(t_num_list_node));
	if (!res)
		ft_put_error_and_exit(stack_group);
	res->num = value;
	return (res);
}

void	init_list(t_stack_group *stack_group)
{
	stack_group->head_a = make_new_ele(stack_group, 0);
	stack_group->head_b = make_new_ele(stack_group, 0);
	stack_group->head_a->prev = stack_group->head_a;
	stack_group->head_a->next = stack_group->head_a;
	stack_group->head_b->prev = stack_group->head_b;
	stack_group->head_b->next = stack_group->head_b;
}

int	get_valid_num(char *value, t_stack_group *stack_group)
{
	int		int_value;

	if (ft_is_all_num(value) == -1)
		ft_put_error_and_exit(stack_group);
	int_value = ft_atoi_ps(value, stack_group);
	return (int_value);
}

int	check_duplicate_value(int value, t_num_list_node *node)
{
	if (value == node->num)
		return (1);
	return (0);
}

//末尾の node を探す。重複がないかチェック
t_num_list_node	*get_tail_node(int value, t_num_list_node *stack_a)
{
	t_num_list_node	*tmp;

	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		if (check_duplicate_value(value, tmp->next))
			return (NULL);
		tmp = tmp->next;
	}
	return tmp;
}

void	add_node_to_stack(int value, t_stack_group *stack_group)
{
	t_num_list_node	*tail_node;
	t_num_list_node	*new_node;

	tail_node = get_tail_node(value, stack_group->head_a);
	if (!tail_node)
		ft_put_error_and_exit(stack_group);
	new_node = make_new_ele(stack_group, value);
	new_node->next = stack_group->head_a;
	new_node->prev = tail_node;
	tail_node->next = new_node;
	stack_group->head_a->prev = new_node;
}

int	main(int ac, char **av)
{
	int		i;
	int		value;

	t_stack_group	stack_group;
	init_list(&stack_group);
	i = 1;
	if (ac == 1)
		ft_exit(&stack_group);
	while (i < ac)
	{
		value = get_valid_num(av[i], &stack_group);
		add_node_to_stack(value, &stack_group);
		i++;
	}
	//test print stack_a
	// t_num_list_node *tmp = stack_group.head_a;
	// while (tmp->next != stack_group.head_a)
	// {
	// 	printf("%d\n", tmp->next->num);
	// 	tmp = tmp->next;
	// }
	// printf("stack_a num	: %d\n", tmp->next->num);

	//標準入力で命令を受け取る
	
	ft_exit(&stack_group);
	return (0);
}
