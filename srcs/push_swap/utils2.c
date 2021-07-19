/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:07:20 by jnakahod          #+#    #+#             */
/*   Updated: 2021/07/19 14:16:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	count_size(t_num_list_node *stack)
{
	t_num_list_node	*tmp;
	int				res;

	res = 0;
	tmp = stack->next;
	while (tmp != stack)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

int	count_digits(int n)
{
	int				digits;
	unsigned int	tmp;

	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	digits = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	if (n < 0)
		digits++;
	return (digits);
}

void	free_only_instr_node(t_instr_list_node **node)
{
	if (*node)
	{
		if ((*node)->instr)
		{
			free((*node)->instr);
			(*node)->instr = NULL;
		}
		free(*node);
		*node = NULL;
	}
}

/*
int	*ft_atoi_ps(const char *str, t_list_group *list_group, t_info *info)
{
	long long	number;
	int 		*res;
	int 		sign;
	int			i;

	(void) list_group;
	(void) info;
	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (check_int_overflow(sign, str + i) == -1)
		return (NULL);
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			number = number * 10;
			number += str[i] - '0';
			i++;
		}
		else
			return (NULL);
	}
	res = (int *)malloc(sizeof(int) * 1);
	if (!res)
		return (NULL);
	*res = (int)number * sign;
	return (res);
}
*/

int	get_valid_num_ps(char *value, t_list_group *list_group, t_info *info)
{
	int	*int_value;
	int	res;

	int_value = ft_atoi_ps(value);
	if (!int_value)
		ft_put_error_and_ps_exit(list_group, info);
	res = *int_value;
	free(int_value);
	return (res);
}
