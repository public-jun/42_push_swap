/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instr_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:54:09 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/05 17:44:55 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

t_instr_list_node	*make_new_instr_node(t_list_group *list_group, char *instr)
{
	t_instr_list_node	*res;

	res = (t_instr_list_node *)malloc(sizeof(t_instr_list_node));
	if (!res)
		ft_put_error_and_exit(list_group);
	res->instr = ft_strdup(instr);
	return (res);
}

// t_instr_list_node	*get_tail_instr_node(t_instr_list_node *head)
// {
// 	t_instr_list_node	*tmp;

// 	tmp = head;
// 	while (tmp->next != head)
// 		tmp = tmp->next;
// 	return (tmp);
// }

void	add_node_to_instr_list(char *line, t_list_group *list_group)
{
	t_instr_list_node	*tail_node;
	t_instr_list_node	*new_node;

	// tail_node = get_tail_instr_node(list_group->head_instr);
	tail_node = list_group->head_instr->prev;
	new_node = make_new_instr_node(list_group, line);
	new_node->next = list_group->head_instr;
	new_node->prev = tail_node;
	tail_node->next = new_node;
	list_group->head_instr->prev = new_node;
}
