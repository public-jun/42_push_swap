/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:10:43 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/06 13:56:25 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
