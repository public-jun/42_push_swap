/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:47:10 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/05 22:52:26 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_info(t_info *info, int num_ac)
{
	info->all_size = num_ac;
	info->a_size = info->all_size;
	info->b_size = 0;
	info->want = 0;
}
