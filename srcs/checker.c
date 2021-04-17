/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 16:31:42 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/common.h"

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
	//標準入力で命令を受け取る
	read_instruction_stdin(&list_group);

	//受け取った命令を実行する
	exec_instruction(&list_group);

	check_list_order(&list_group);
	return (0);
}
