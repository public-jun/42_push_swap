/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:51:25 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/06 13:51:48 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	int		i;
	int		value;
	int		num_ac;
	t_list_group	list_group;
	t_info	info;

	init_list(&list_group);
	i = 1;
	// check option
	num_ac = ac - 1;
	if (ac == 1)
		ft_exit(&list_group);
	while (i < num_ac)
	{
		value = get_valid_num(av[i], &list_group);
		add_value_to_pair(&info, value, i - 1, &list_group);
		i++;
	}
	init_info(&info, num_ac);
	set_pair_info(&list_group, &info);
	copy_stack_a(&list_group);
	no_sort(&list_group, &info);
	if (num_ac < 6)
		sort_less6(&info, &list_group, num_ac);
	else
		sort_over5(&list_group, &info);
	instr_optimization(&list_group);
	option_v(&list_group, &info);
	printf("\n---instr_list-----\n");
	t_instr_list_node *instr_p = list_group.head_instr;
	int instr_count = 0;
	while (instr_p->next != list_group.head_instr)
	{
		printf("%s\n", instr_p->next->instr);
		instr_p = instr_p->next;
		instr_count++;
	}
	printf("instr_count : %d\n", instr_count);
	ft_info_free(&info);
	ft_exit(&list_group);
	return (0);
}
