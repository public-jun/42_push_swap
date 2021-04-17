/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:29:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 16:19:05 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/common.h"

int			ft_is_all_num(char *num)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(num);
	if (len > 1 && num[i] == '0')
		return (-1);
	i = 0;
	while (ft_isdigit(num[i]))
		i++;
	if (i == len)
		return (0);
	return (-1);
}

static int	check_int_overflow(int sign, const char *str)
{
	int		digit;

	digit = 0;
	while (ft_isdigit(str[digit]))
		digit++;
	if (digit > 10)
		return (-1);
	if ((sign == 1 && ft_strncmp(str, "2147483647", 19) > 0)
		&& digit == 10)
		return (-1);
	if ((sign == -1 && ft_strncmp(str, "2147483648", 19) > 0)
		&& digit == 10)
		return (-1);
	return (1);
}

int	ft_atoi_ps(const char *str, t_list_group *list_group)
{
	long long		number;
	int				sign;
	int				i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (check_int_overflow(sign, str + i) == -1)
		ft_put_error_and_exit(list_group);
	while (ft_isdigit(str[i]))
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
