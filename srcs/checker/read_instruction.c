/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:29:44 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/24 17:58:12 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	check_valid_instruction(char *line)
{
	if ((ft_strncmp(line, "sa", 3)) && (ft_strncmp(line, "sb", 3)) && (ft_strncmp(line, "ss", 3)) && (ft_strncmp(line, "pa", 3)) && (ft_strncmp(line, "pb", 3)) && (ft_strncmp(line, "ra", 3)) && (ft_strncmp(line, "rb", 3)) && (ft_strncmp(line, "rr", 3)) && (ft_strncmp(line, "rra", 4)) && (ft_strncmp(line, "rrb", 4)) && (ft_strncmp(line, "rrr", 4)))
		return (-1);
	return (0);
}


void	read_instruction_stdin(t_list_group *list_group)
{
	int		res;
	char	*line;

	res = 1;
	while (res > 0)
	{
		res = get_next_line(0, &line);
		if (res == 0)
			break ;
		if (check_valid_instruction(line) < 0 || res == -1)
		{
			get_next_line(0, NULL);
			free(line);
			ft_put_error_and_exit(list_group);
		}
		add_node_to_instr_list(line, list_group);
		free(line);
	}
	free(line);
}
