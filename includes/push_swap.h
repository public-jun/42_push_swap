/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 00:12:39 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../libft/libft.h"
#include "common.h"

# define SORT_ID 1
# define SORT_VALUE 0
# define ESC 0x1b

/*
** init_info
*/
void	init_info(t_list_group *list_group, t_info *info);
void	add_value_to_pair(t_info *info, int value, int i, t_list_group *list_group);
void	set_pair_info(t_list_group *list_group, t_info *info);

void	quick_sort(t_pair n[], int left, int right, int flag);
void	sort_over5(t_list_group *list_group, t_info *info);
t_pivot *free_one_pivot_node(t_pivot *node);
void	ft_info_free(t_info *info);
void	ft_put_error_and_ps_exit(t_list_group *list_group, t_info *info);
void	add_front_pivot_list(int pivot, t_list_group *list_group, t_info *info);
void	instr_optimization(t_list_group *list_group);
/*
** exec_instr
*/
void	exec_s_r_and_add_instr_node(void (*f)(t_num_list_node *), t_num_list_node *stack,char *instr, t_list_group *list_group, t_info *info);
void	exec_p_and_add_instr_node(t_num_list_node *from, t_num_list_node *to, t_list_group *list_group, t_info *info);
/*
** sort_only_3_node
*/
void	sort_only_three(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case1(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case2(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case3(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case4(t_num_list_node *stack, t_list_group *list_group, t_info *info);
void	sort_only_three_case5(t_num_list_node *stack, t_list_group *list_group, t_info *info);
/*
** sort_less6
*/
void	sort_less6(t_info *info, t_list_group *list_group);
t_pivot	*make_new_pivot(t_list_group *list_group, t_info *info, int pivot);
/*
** utils
*/
int		find_min_value(t_num_list_node *head);
void	min_move_top(t_num_list_node *stack, int min, t_info *info, t_list_group *list_group, int size);
void	pa_all_node(t_list_group *list_group, t_info *info);
int		count_size(t_num_list_node *stack);
void	no_sort(t_list_group *list_group, t_info *info);
int	count_digits(int n);
void	free_only_instr_node(t_instr_list_node **node);
/*
** print_ans
*/
void	print_ans(t_list_group *list_group);
/*
** option -v
*/
void	option_v(t_list_group *list_group, t_info *info);
void	copy_stack_a(t_list_group *group);
/*
** debug
*/
void	print_space_num(int s_size, int num, int left_flag);
void	print_sort_result1(t_list_group *list_group, t_info *info);
void	print_one_node(int id, int num);



#endif
