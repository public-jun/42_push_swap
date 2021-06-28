/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:51:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/28 21:04:19 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	get_num_from_arg2(char **av,
	t_list_group *list_group, t_info *info)
{
	int		i;
	int		value;

	i = 0;
	info->split_av = ft_split(av[1], ' ');
	if (!info->split_av)
		ft_put_error_and_ps_exit(list_group, info);
	info->all_size = count_num_size(info->split_av);
	while (i < info->all_size)
	{
		value = get_valid_num_ps(info->split_av[i], list_group, info);
		add_value_to_pair(info, value, i, list_group);
		i++;
	}
	ft_free_all(info->split_av);
	info->split_av = NULL;
	if (info->all_size < 2)
		ft_exit_ps(list_group, info);
}

void	get_num_from_arg1(int ac, char **av,
	t_list_group *list_group, t_info *info)
{
	int	i;
	int	f;
	int	value;

	i = 0;
	f = 1;
	if (info->a_flag || info->v_flag || info->c_flag)
		f++;
	if (ac == 2)
		get_num_from_arg2(av, list_group, info);
	else
	{
		while (i < info->all_size)
		{
			value = get_valid_num_ps(av[i + f], list_group, info);
			add_value_to_pair(info, value, i, list_group);
			i++;
		}
	}
	info->a_size = info->all_size;
}

/*
void	check_option(int ac, char **av, t_list_group *list_group, t_info *info)
{
	if (av[1][0] == '-' && ft_is_all_num(av[1]) == -1)
	{
		if (ft_strchr(av[1], 'v'))
			info->v_flag = 1;
		if (ft_strchr(av[1], 'a'))
			info->a_flag = 1;
		if (ft_strchr(av[1], 'c'))
			info->c_flag = 1;
		if (!info->v_flag && !info->a_flag && !info->c_flag)
			ft_put_error_and_ps_exit(list_group, info);
		info->all_size = ac - 2;
	}
	else
		info->all_size = ac - 1;
}
*/

void	check_option(int ac, char **av, t_list_group *list_group, t_info *info)
{
	(void) av;
	(void) list_group;
	info->all_size = ac - 1;
}

int	main(int ac, char **av)
{
	int				i;
	t_list_group	list_group;
	t_info			info;

	init_list(&list_group);
	init_info(&list_group, &info);
	i = 1;
	if (ac == 1)
		ft_exit_ps(&list_group, &info);
	check_option(ac, av, &list_group, &info);
	get_num_from_arg1(ac, av, &list_group, &info);
	set_pair_info(&list_group, &info);
	copy_stack_a(&list_group);
	no_sort(&list_group, &info);
	if (info.all_size < 6)
		sort_less6(&info, &list_group);
	else
		sort_over5(&list_group, &info);
	instr_optimization(&list_group);
	exe_option(&list_group, &info);
	print_ans(&list_group, &info);
	ft_exit_ps(&list_group, &info);
	return (0);
}
