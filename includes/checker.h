/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:30 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 18:13:38 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "struct.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include "common.h"

void	read_instruction_stdin(t_list_group *list_group);
void	check_list_order(t_list_group *list_group);
#endif
