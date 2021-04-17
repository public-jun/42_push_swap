/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 15:20:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/common.h"

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

t_instr_list_node	*free_one_instr_node(t_instr_list_node *node)
{
	t_instr_list_node *tmp_prev;

	tmp_prev = node->prev;
	node->next->prev = tmp_prev;
	tmp_prev->next = node->next;
	free(node->instr);
	node->instr = NULL;
	free(node);
	node = NULL;
	return (tmp_prev->next);
}

void	ft_exit(t_list_group *list_group)
{
	t_num_list_node		*tmp;
	t_instr_list_node	*tmp_instr;

	tmp = list_group->stack_a->next;
	while (tmp != list_group->stack_a)
		tmp = free_one_node(tmp);
	free(list_group->stack_a);
	list_group->stack_a = NULL;
	tmp = list_group->stack_b->next;
	while (tmp != list_group->stack_b)
		tmp = free_one_node(tmp);
	free(list_group->stack_b);
	list_group->stack_b = NULL;
	tmp_instr = list_group->head_instr->next;
	while (tmp_instr != list_group->head_instr)
		tmp_instr = free_one_instr_node(tmp_instr);
	free(list_group->head_instr->instr);
	free(list_group->head_instr);
	exit(0);
}

void	ft_put_error_and_exit(t_list_group *list_group)
{
	write(2, "Error\n", 6);
	ft_exit(list_group);
}

t_num_list_node *make_new_ele(t_list_group *list_group, int value)
{
	t_num_list_node *res;

	res = (t_num_list_node*)malloc(sizeof(t_num_list_node));
	if (!res)
		ft_put_error_and_exit(list_group);
	res->num = value;
	return (res);
}

void	init_instr_list(t_list_group *list_group)
{
	list_group->head_instr = make_new_instr_node(list_group, NULL);
	list_group->head_instr->prev = list_group->head_instr;
	list_group->head_instr->next = list_group->head_instr;
}

void	init_list(t_list_group *list_group)
{
	list_group->stack_a = make_new_ele(list_group, 0);
	list_group->stack_b = make_new_ele(list_group, 0);
	list_group->stack_a->prev = list_group->stack_a;
	list_group->stack_a->next = list_group->stack_a;
	list_group->stack_b->prev = list_group->stack_b;
	list_group->stack_b->next = list_group->stack_b;
	init_instr_list(list_group);
}

int	get_valid_num(char *value, t_list_group *list_group)
{
	int		int_value;

	if (ft_is_all_num(value) == -1)
		ft_put_error_and_exit(list_group);
	int_value = ft_atoi_ps(value, list_group);
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
	return (tmp);
}

void	add_node_to_stack(int value, t_list_group *list_group)
{
	t_num_list_node	*tail_node;
	t_num_list_node	*new_node;

	tail_node = get_tail_node(value, list_group->stack_a);
	if (!tail_node)
		ft_put_error_and_exit(list_group);
	new_node = make_new_ele(list_group, value);
	new_node->next = list_group->stack_a;
	new_node->prev = tail_node;
	tail_node->next = new_node;
	list_group->stack_a->prev = new_node;
}

int	main(int ac, char **av)
{
	int		i;
	int		value;

	t_list_group	list_group;
	init_list(&list_group);
	i = 1;
	if (ac == 1)
		ft_exit(&list_group);
	while (i < ac)
	{
		value = get_valid_num(av[i], &list_group);
		add_node_to_stack(value, &list_group);
		i++;
	}
	//test print stack_a
	// t_num_list_node *tmp = list_group.stack_a;
	// while (tmp->next != list_group.stack_a)
	// {
	// 	printf("%d\n", tmp->next->num);
	// 	tmp = tmp->next;
	// }
	// printf("stack_a num	: %d\n", tmp->next->num);

	//標準入力で命令を受け取る
	read_instruction_stdin(&list_group);
	// test print instr_list
	// t_instr_list_node *instr_tmp = list_group.head_instr;
	// while (instr_tmp->next != list_group.head_instr)
	// {
	// 	printf("%s\n", instr_tmp->next->instr);
	// 	instr_tmp = instr_tmp->next;
	// }
	// printf("head_instr	: %s\n", instr_tmp->next->instr);

	//受け取った命令を実行する
	exec_instruction(&list_group);
	// test print stack_a
	// t_num_list_node *tmp = list_group.stack_a;
	// printf("\n---result-----\n");
	// while (tmp->next != list_group.stack_a)
	// {
	// 	printf("%d\n", tmp->next->num);
	// 	tmp = tmp->next;
	// }
	// printf("stack_a num	: %d\n", tmp->next->num);

	check_list_order(&list_group);
	t_num_list_node *tmp = list_group.stack_a;
	printf("\n---result-----\n");
	while (tmp->next != list_group.stack_a)
	{
		printf("%d\n", tmp->next->num);
		tmp = tmp->next;
	}
	printf("stack_a num	: %d\n", tmp->next->num);
	return (0);
}
