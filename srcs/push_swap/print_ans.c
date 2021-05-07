/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:47 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 12:00:19 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_ans(t_list_group *list_group)
{
	t_instr_list_node *tmp;
	int instr_count;

	tmp = list_group->head_instr->next;
	instr_count = 0;
	// printf("\n---instr_list-----\n");
	while (tmp->next != list_group->head_instr)
	{
		ft_putendl_fd(tmp->instr, 1);
		tmp = tmp->next;
		instr_count++;
	}
	ft_putendl_fd(tmp->instr, 1);
	// printf("instr_count : %d\n", instr_count);
}
