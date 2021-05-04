/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_optimazation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 01:36:13 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/03 17:28:42 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	instr_optimization(t_list_group *list_group)
{
	t_instr_list_node *tmp;
	t_instr_list_node *tmp_prev;
	t_instr_list_node *head;
	t_instr_list_node *new;
	int	loop = 0;

	tmp = list_group->head_instr->next;
	head = list_group->head_instr;

	while (tmp != head)
	{
		//pa + pb || pb + pa 削除
		if ((!(ft_strncmp(tmp->instr, "pa", 3)) && !(ft_strncmp(tmp->next->instr, "pb", 3)))
		|| (!(ft_strncmp(tmp->instr, "pb", 3)) && !(ft_strncmp(tmp->next->instr, "pa", 3))))
		{
			tmp->prev->next = tmp->next->next;
			tmp->next->next->prev = tmp->prev;
			tmp_prev = tmp->prev;
			free_only_instr_node(&(tmp->next));
			free_only_instr_node(&(tmp));
			tmp = tmp_prev;
		}
		//sa + sb || sb + sa => ss
		else if ((!(ft_strncmp(tmp->instr, "sa", 3)) && !(ft_strncmp(tmp->next->instr, "sb", 3)))
		|| (!(ft_strncmp(tmp->instr, "sb", 3)) && !(ft_strncmp(tmp->next->instr, "sa", 3))))
		{
			new = make_new_instr_node(list_group, "ss");
			new->prev = tmp->prev;
			new->next = tmp->next->next;
			tmp->prev->next = new;
			tmp->next->next->prev = new;
			free_only_instr_node(&(tmp->next));
			free_only_instr_node(&tmp);
			tmp = new;
		}
		//ra + rb || rb + ra => rr
		else if ((!(ft_strncmp(tmp->instr, "ra", 3)) && !(ft_strncmp(tmp->next->instr, "rb", 3)))
		|| (!(ft_strncmp(tmp->instr, "rb", 3)) && !(ft_strncmp(tmp->next->instr, "ra", 3))))
		{
			new = make_new_instr_node(list_group, "rr");
			new->prev = tmp->prev;
			new->next = tmp->next->next;
			tmp->prev->next = new;
			tmp->next->next->prev = new;
			free_only_instr_node(&(tmp->next));
			free_only_instr_node(&tmp);
			tmp = new;
		}
		//rra + rrb || rrb + rra => rrr
		else if ((!(ft_strncmp(tmp->instr, "rra", 4)) && !(ft_strncmp(tmp->next->instr, "rrb", 4)))
		|| (!(ft_strncmp(tmp->instr, "rrb", 4)) && !(ft_strncmp(tmp->next->instr, "rra", 4))))
		{
			new = make_new_instr_node(list_group, "rrr");
			new->prev = tmp->prev;
			new->next = tmp->next->next;
			tmp->prev->next = new;
			tmp->next->next->prev = new;
			free_only_instr_node(&(tmp->next));
			free_only_instr_node(&tmp);
			tmp = new;
		}
		else
			tmp = tmp->next;
		loop++;
	}
	//rra + rrb || rrb + rra => rrr
}
