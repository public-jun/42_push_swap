/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:29:44 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/17 17:41:00 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_instr_list_node	*make_new_instr_node(t_list_group *list_group, char *instr)
{
	t_instr_list_node	*res;

	res = (t_instr_list_node *)malloc(sizeof(t_instr_list_node));
	if (!res)
		ft_put_error_and_exit(list_group);
	res->instr = ft_strdup(instr);
	return (res);
}

int	check_valid_instruction(char *line)
{
	if ((ft_strncmp(line, "sa", 3)) && (ft_strncmp(line, "sb", 3)) && (ft_strncmp(line, "ss", 3)) && (ft_strncmp(line, "pa", 3)) && (ft_strncmp(line, "pb", 3)) && (ft_strncmp(line, "ra", 3)) && (ft_strncmp(line, "rb", 3)) && (ft_strncmp(line, "rr", 3)) && (ft_strncmp(line, "rra", 4)) && (ft_strncmp(line, "rrb", 4)) && (ft_strncmp(line, "rrr", 4)))
		return (-1);
	return (0);
}

t_instr_list_node	*get_tail_instr_node(t_instr_list_node *head)
{
	t_instr_list_node	*tmp;

	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	return (tmp);
}

void	add_node_to_instr_list(char *line, t_list_group *list_group)
{
	t_instr_list_node	*tail_node;
	t_instr_list_node	*new_node;

	tail_node = get_tail_instr_node(list_group->head_instr);
	new_node = make_new_instr_node(list_group, line);
	new_node->next = list_group->head_instr;
	new_node->prev = tail_node;
	tail_node->next = new_node;
	list_group->head_instr->prev = new_node;
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
