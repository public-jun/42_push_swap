/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:30 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 01:29:08 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"
//printf
#include <stdio.h>


int	ft_is_all_num(char *num);
int	ft_atoi_ps(const char *str, t_list_group *list_group);
void	ft_put_error_and_exit(t_list_group *list_group);
t_instr_list_node	*make_new_instr_node(t_list_group *list_group, char *instr);
void	read_instruction_stdin(t_list_group *list_group);
#endif
