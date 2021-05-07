/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 11:50:47 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"


void	get_num(int ac, char **av, t_list_group *list_group)
{
	char	**split_av;
	int		size;
	int		i;
	int		value;

	split_av = NULL;
	size = ac - 1;
	i = 0;
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		if (!split_av)
			ft_put_error_and_exit(list_group);
		size = count_num_size(split_av);
		if (size > 1)
		{
			while (i < size)
			{
				if (ft_is_all_num(split_av[i]) == -1)
				{
					ft_free_all(split_av);
					ft_put_error_and_exit(list_group);
				}
				value = get_valid_num(split_av[i], list_group);
				add_node_to_stack(value, list_group);
				i++;
			}
			ft_free_all(split_av);
		}
	}
	else
	{
		while (i < size)
		{
			value = get_valid_num(av[i + 1], list_group);
			add_node_to_stack(value, list_group);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int				i;
	t_list_group	list_group;

	init_list(&list_group);
	i = 1;
	if (ac == 1)
		ft_exit(&list_group);
	get_num(ac, av, &list_group);
	//標準入力で命令を受け取る
	read_instruction_stdin(&list_group);

	//受け取った命令を実行する
	exec_instruction(&list_group);

	check_list_order(&list_group);
	return (0);
}
