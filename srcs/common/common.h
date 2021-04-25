/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:37:40 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/24 17:57:10 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../../libft/libft.h"

#include <stdio.h>

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
void	exec_instruction(t_list_group *list_group);
void	ft_exit(t_list_group *list_group);
void	ft_put_error_and_exit(t_list_group *list_group);
t_num_list_node *free_one_node(t_num_list_node *node);
t_instr_list_node	*free_one_instr_node(t_instr_list_node *node);
#endif
