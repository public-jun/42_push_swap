/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:19:46 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/05 22:27:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_pivot *free_one_pivot_node(t_pivot *node)
{
	t_pivot *tmp_prev;

	tmp_prev = node->prev;
	node->next->prev = tmp_prev;
	tmp_prev->next = node->next;
	free(node);
	return (tmp_prev->next);
}

void	ft_info_free(t_info *info)
{
	t_pivot *tmp;

	tmp = info->p_head->next;
	while (tmp != info->p_head)
		tmp = free_one_pivot_node(tmp);
	free(info->p_head);
}

void	ft_put_error_and_ps_exit(t_list_group *list_group, t_info *info)
{
	write(2, "Error\n", 6);
	ft_info_free(info);
	ft_exit(list_group);
}
