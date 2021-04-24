/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:18 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/24 16:14:05 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		
	}
}
