/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:53:35 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/26 00:06:45 by jnakahod         ###   ########.fr       */
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

typedef struct s_info
{
	t_pair	n[ARGLIMIT + 10];
	int		def[ARGLIMIT + 10];
	int		n_size;
}	t_info;

void	quick_sort(t_pair n[], int left, int right, int flag);
// void	quick_sort_id(t_pair n[], int left, int right);
// void	quick_sort_value(t_pair n[], int left, int right);

#endif
