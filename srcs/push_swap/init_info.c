/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:47:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 21:12:57 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pivot_init(t_info *info, t_list_group *list_group)
{
	info->p_head = make_new_pivot(list_group, info, 0);
	info->p_head->prev = info->p_head;
	info->p_head->next = info->p_head;
}

void	init_info(t_list_group *list_group, t_info *info)
{
	info->split_av = NULL;
	info->all_size = 0;
	info->a_size = 0;
	info->b_size = 0;
	info->want = 0;
	info->v_flag = 0;
	info->a_flag = 0;
	info->c_flag = 0;
	int i = 0;
	while (i < ARGLIMIT + 10)
	{
		info->n[i].value = 0;
		info->n[i].id = 0;
		info->def[i++] = 0;
	}
	pivot_init(info, list_group);
}
