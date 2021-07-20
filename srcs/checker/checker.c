/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:38:58 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/20 11:06:47 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	get_value_and_free(int **p_value)
{
	int	res;

	res = **p_value;
	free(*p_value);
	*p_value = NULL;
	return (res);
}

void	get_num2(char **av, t_list_group *list_group)
{
	char	**split_av;
	int		size;
	int		i;
	int		value;
	int		*int_value;

	i = -1;
	split_av = ft_split(av[1], ' ');
	if (!split_av)
		ft_put_error_and_exit(list_group);
	size = count_num_size(split_av);
	if (size > ARGLIMIT || !size)
		ft_put_error_and_exit(list_group);
	while (++i < size)
	{
		int_value = ft_atoi_ps(split_av[i]);
		if (!int_value)
		{
			ft_free_all(split_av);
			ft_put_error_and_exit(list_group);
		}
		value = get_value_and_free(&int_value);
		add_node_to_stack(value, list_group);
	}
	ft_free_all(split_av);
}

void	get_num1(int ac, char **av, t_list_group *list_group)
{
	char	**split_av;
	int		size;
	int		i;
	int		value;
	int		*int_value;

	split_av = NULL;
	size = ac - 1;
	i = 0;
	if (ac == 2)
		get_num2(av, list_group);
	else
	{
		if (size > ARGLIMIT)
			ft_put_error_and_exit(list_group);
		while (i < size)
		{
			int_value = ft_atoi_ps(av[i + 1]);
			if (!int_value)
				ft_put_error_and_exit(list_group);
			value = get_value_and_free(&int_value);
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
