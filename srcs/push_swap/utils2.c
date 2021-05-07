/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:07:20 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 00:12:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	count_digits(int n)
{
	int				digits;
	unsigned int	tmp;

	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	digits = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	if (n < 0)
		digits++;
	return (digits);
}

void	free_only_instr_node(t_instr_list_node **node)
{
	if (*node)
	{
		if ((*node)->instr)
		{
			free((*node)->instr);
			(*node)->instr = NULL;
		}
		free(*node);
		*node = NULL;
	}
}
