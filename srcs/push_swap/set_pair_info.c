/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pair_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:58:45 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 21:30:16 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_value_to_pair(t_info *info, int value, int i,
	t_list_group *list_group)
{
	int	j;

	if (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (value == info->n[j].value)
				ft_put_error_and_ps_exit(list_group, info);
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

void	set_pair_info(t_list_group *list_group, t_info *info)
{
	quick_sort(info->n, 0, info->all_size - 1, SORT_VALUE);
	convert_val_to_id(info);
	quick_sort(info->n, 0, info->all_size - 1, SORT_ID);
	make_stack_num_is_id(info, list_group);
}
