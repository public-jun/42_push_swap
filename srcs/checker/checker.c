/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/21 11:37:00 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	add_node(int size, char **split_av, t_list_group *list_group)
{
	int	exit_flag;
	int	i;
	int	value;

	exit_flag = 0;
	i = 0;
	if (size == 1 && ft_is_all_num(split_av[0]) == -1)
		exit_flag = 1;
	while (i < size && size > 1)
	{
		if (ft_is_all_num(split_av[i]) == -1)
		{
			exit_flag = 1;
			break ;
		}
		value = get_valid_num(split_av[i], list_group);
		add_node_to_stack(value, list_group);
		i++;
	}
	ft_free_all(split_av);
	if (exit_flag)
		ft_put_error_and_exit(list_group);
}

void	get_num2(char **av, t_list_group *list_group)
{
	char	**split_av;
	int		size;

	split_av = ft_split(av[1], ' ');
	if (!split_av)
		ft_put_error_and_exit(list_group);
	size = count_num_size(split_av);
	add_node(size, split_av, list_group);
}

void	get_num1(int ac, char **av, t_list_group *list_group)
{
	char	**split_av;
	int		size;
	int		i;
	int		value;

	split_av = NULL;
	size = ac - 1;
	i = 0;
	if (ac == 2)
		get_num2(av, list_group);
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
	get_num1(ac, av, &list_group);
	read_instruction_stdin(&list_group);
	exec_instruction(&list_group);
	check_list_order(&list_group);
	return (0);
}
