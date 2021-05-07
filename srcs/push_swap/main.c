/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:51:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 13:26:38 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_num_from_arg(int ac, char **av, t_list_group *list_group, t_info *info)
{
	int	i;
	int	value;

	i = 0;
	info->all_size = 0;
	info->split_av = NULL;
	if (ac == 2)
	{
		info->split_av = ft_split(av[1], ' ');
		info->all_size = count_num_size(info->split_av);
		if (info->all_size > 1)
		{
			while (i < info->all_size)
			{
				if (ft_is_all_num(info->split_av[i]) == -1)
					ft_put_error_and_ps_exit(list_group, info);
				value = get_valid_num(info->split_av[i], list_group);
				add_value_to_pair(info, value, i, list_group);
				i++;
			}
		}
		else
			ft_exit(list_group);
	}
	else
	{
		info->all_size = ac - 1;
		while (i < info->all_size)
		{
			value = get_valid_num(av[i + 1], list_group);
			add_value_to_pair(info, value, i, list_group);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_list_group	list_group;
	t_info	info;

	init_list(&list_group);
	i = 1;
	// check option
	if (ac == 1)
		ft_exit(&list_group);
	get_num_from_arg(ac, av, &list_group, &info);
	init_info(&list_group, &info);
	set_pair_info(&list_group, &info);
	copy_stack_a(&list_group);
	no_sort(&list_group, &info);
	if (info.all_size < 6)
		sort_less6(&info, &list_group);
	else
		sort_over5(&list_group, &info);
	instr_optimization(&list_group);
	// option_v(&list_group, &info);
	print_ans(&list_group);
	ft_info_free(&info);
	ft_exit(&list_group);
	return (0);
}
