/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:29:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/06/21 17:56:17 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	count_num_size(char **dst)
{
	int	res;

	res = 0;
	while (dst[res])
		res++;
	return (res);
}

static int	check_over_flow_in_ft_is_all_num(int sign, char *num)
{
	if (sign == -1)
	{
		if (check_int_overflow(sign, num + 1) == -1)
			return (-1);
	}
	else
	{
		if (check_int_overflow(sign, num) == -1)
			return (-1);
	}
	return (0);
}

int	ft_is_all_num(char *num)
{
	int		len;
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	len = (int)ft_strlen(num);
	if (len > 1 && num[i] == '0')
		return (-1);
	i = 0;
	if (num[i] == '-')
	{
		i++;
		sign = -1;
	}
	res = check_over_flow_in_ft_is_all_num(sign, num);
	while (ft_isdigit(num[i]))
		i++;
	if (i == len && res != -1)
		return (0);
	return (res);
}

int	check_int_overflow(int sign, const char *str)
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

int	ft_atoi_ch(const char *str, t_list_group *list_group)
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
