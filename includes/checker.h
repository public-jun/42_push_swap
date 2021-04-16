/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:30 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/16 16:39:10 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"
#include "../libft/libft.h"
//printf
#include <stdio.h>


int	ft_is_all_num(char *num);
int	ft_atoi_ps(const char *str, t_stack_group *stack_group);
void	ft_put_error_and_exit(t_stack_group *stack_group);
