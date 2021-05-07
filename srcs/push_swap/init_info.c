/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:47:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 11:02:06 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pivot_init(t_info *info, t_list_group *list_group)
{
	info->p_head = make_new_pivot(list_group, info, 0);
	info->p_head->prev = info->p_head;
	info->p_head->next = info->p_head;
}

void	init_info(t_list_group *list_group,  t_info *info)
{
	info->a_size = info->all_size;
	info->b_size = 0;
	info->want = 0;
	pivot_init(info, list_group);
}
