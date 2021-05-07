/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:37:40 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/07 22:00:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../libft/libft.h"
#include <stdio.h>

# define CLEAR "\033[2J"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define DEFCOLOR "\033[39m"
# define BLACK "\033[30m"
# define INVERSION "\033[7m"
# define DEFSET "\033[0m"
# define EMPHASIZE "\033[1m"
# define WHITE_BACK "\033[47m"
# define DEFCOLOR_BACK "\033[49m"

void	init_instr_list(t_list_group *list_group);
void	init_list(t_list_group *list_group);
int	ft_is_all_num(char *num);
int	ft_atoi_ps(const char *str, t_list_group *list_group);
t_num_list_node *make_new_ele(t_list_group *list_group, int value);
int	get_valid_num(char *value, t_list_group *list_group);
int	check_duplicate_value(int value, t_num_list_node *node);
t_num_list_node	*get_tail_node(int value, t_num_list_node *stack_a);
void	add_node_to_stack(int value, t_list_group *list_group);
void	add_node_to_instr_list(char *line, t_list_group *list_group);
t_instr_list_node	*get_tail_instr_node(t_instr_list_node *head);
t_instr_list_node	*make_new_instr_node(t_list_group *list_group, char *instr);
void	ft_exit(t_list_group *list_group);
void	ft_put_error_and_exit(t_list_group *list_group);
t_num_list_node *free_one_node(t_num_list_node *node);
t_instr_list_node	*free_one_instr_node(t_instr_list_node *node);
int		count_num_size(char **dst);
/*
** instructions
*/
void	exec_r(t_num_list_node *stack);
void	exec_s(t_num_list_node *stack);
void	exec_rr(t_num_list_node *stack);
void	exec_p(t_num_list_node *from, t_num_list_node *to);
void	exec_instruction(t_list_group *list_group);
void	conditional_branch_by_instr1(t_num_list_node *a, t_num_list_node *b, char *instr);
#endif
