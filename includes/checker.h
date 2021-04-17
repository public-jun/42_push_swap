/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:30 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 18:13:11 by jnakahod         ###   ########.fr       */
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
#include "../srcs/common/common.h"
//printf
#include <stdio.h>


void	read_instruction_stdin(t_list_group *list_group);
void	check_list_order(t_list_group *list_group);
#endif
