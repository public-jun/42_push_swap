/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/01 19:33:28 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../libft/libft.h"
#include "../srcs/common/common.h"

# define ARGLIMIT 1001
# define SORT_VALUE 0
# define SORT_ID 1

typedef struct s_pair
{
	int		value;
	int		id;
}	t_pair;

typedef struct s_pivot
{
	int		p_value;
	struct s_pivot	*next;
	struct s_pivot	*prev;
}	t_pivot;

typedef struct s_info
{
	t_pair	n[ARGLIMIT + 10];
	int		def[ARGLIMIT + 10];
	t_pivot	*p_head;
	int		all_size;
	int		a_size;
	int		b_size;
	int		a_min;
	int		b_min;
	int		want;
	int		b_want;
}	t_info;

void	quick_sort(t_pair n[], int left, int right, int flag);
void	sort_only_three_case1(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case2(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case3(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case4(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case5(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	exec_s_r_and_add_instr_node(void (*f)(t_num_list_node *), t_num_list_node *stack,char *instr, t_list_group *list_group, t_info *info);
void	exec_p_and_add_instr_node(t_num_list_node *from, t_num_list_node *to, char *instr, t_list_group *list_group, t_info *info);
void	sort_over5(t_list_group *list_group, t_info *info);
t_pivot *free_one_pivot_node(t_pivot *node);
void	ft_info_free(t_info *info);
void	ft_put_error_and_ps_exit(t_list_group *list_group, t_info *info);
void	add_front_pivot_list(int pivot, t_list_group *list_group, t_info *info);
int		find_min_value(t_num_list_node *head);
void	min_move_top(t_num_list_node *stack, int min, t_info *info, t_list_group *list_group, int size);

#endif
