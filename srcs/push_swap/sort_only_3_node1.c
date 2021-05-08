/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only_3_node1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:37:43 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 15:30:19 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_only_three(t_num_list_node *stack, t_list_group *list_group,
	t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = stack->next->num;
	second = stack->next->next->num;
	third = stack->next->next->next->num;
	if (first > second && second < third && first < third)
		sort_only_three_case1(stack, list_group, info);
	else if (first > second && second > third && first > third)
		sort_only_three_case2(stack, list_group, info);
	else if (first > second && second < third && first > third)
		sort_only_three_case3(stack, list_group, info);
	else if (first < second && second > third && first < third)
		sort_only_three_case4(stack, list_group, info);
	else if (first < second && second > third && first > third)
		sort_only_three_case5(stack, list_group, info);
}
