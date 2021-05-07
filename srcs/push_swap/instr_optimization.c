/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 01:36:13 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 00:37:39 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_instr_list_node	*combine_instr(t_instr_list_node *tmp,
	char *instr, t_list_group *list_group)
{
	t_instr_list_node	*new;

	new = make_new_instr_node(list_group, instr);
	new->prev = tmp->prev;
	new->next = tmp->next->next;
	tmp->prev->next = new;
	tmp->next->next->prev = new;
	free_only_instr_node(&(tmp->next));
	free_only_instr_node(&tmp);
	return (new);
}

t_instr_list_node	*s_r_p_to_p_r(t_instr_list_node *tmp)
{
	t_instr_list_node	*tmp_prev;
	t_instr_list_node	*r;
	t_instr_list_node	*p;
	t_instr_list_node	*tmp_next;

	tmp_prev = tmp->prev;
	r = tmp->next;
	p = tmp->next->next;
	tmp_next = tmp->next->next->next;
	tmp_prev->next = p;
	p->prev = tmp_prev;
	p->next = r;
	r->prev = p;
	r->next = tmp_next;
	tmp_next->prev = r;
	free_only_instr_node(&tmp);
	return (tmp_prev);
}

t_instr_list_node	*push_delete(t_instr_list_node *tmp)
{
	t_instr_list_node	*tmp_prev;

	tmp->prev->next = tmp->next->next;
	tmp->next->next->prev = tmp->prev;
	tmp_prev = tmp->prev;
	free_only_instr_node(&(tmp->next));
	free_only_instr_node(&(tmp));
	return (tmp_prev);
}

void	instr_optimization2(t_instr_list_node **tmp, t_list_group *list_group)
{
	if ((!(ft_strncmp((*tmp)->instr, "rra", 4))
			&& !(ft_strncmp((*tmp)->next->instr, "rrb", 4)))
		|| (!(ft_strncmp((*tmp)->instr, "rrb", 4))
			&& !(ft_strncmp((*tmp)->next->instr, "rra", 4))))
		*tmp = combine_instr(*tmp, "rrr", list_group);
	else if ((!(ft_strncmp((*tmp)->instr, "sa", 3))
			&& !(ft_strncmp((*tmp)->next->instr, "ra", 3))
			&& !(ft_strncmp((*tmp)->next->next->instr, "pb", 3))))
		*tmp = s_r_p_to_p_r(*tmp);
	else if ((!(ft_strncmp((*tmp)->instr, "sb", 3))
			&& !(ft_strncmp((*tmp)->next->instr, "rb", 3))
			&& !(ft_strncmp((*tmp)->next->next->instr, "pa", 3))))
		*tmp = s_r_p_to_p_r(*tmp);
	else
		*tmp = (*tmp)->next;
}

void	instr_optimization(t_list_group *list_group)
{
	t_instr_list_node	*tmp;
	t_instr_list_node	*head;

	tmp = list_group->head_instr->next;
	head = list_group->head_instr;
	while (tmp != head)
	{
		if ((!(ft_strncmp(tmp->instr, "pa", 3))
				&& !(ft_strncmp(tmp->next->instr, "pb", 3)))
			|| (!(ft_strncmp(tmp->instr, "pb", 3))
				&& !(ft_strncmp(tmp->next->instr, "pa", 3))))
			tmp = push_delete(tmp);
		else if ((!(ft_strncmp(tmp->instr, "sa", 3))
				&& !(ft_strncmp(tmp->next->instr, "sb", 3)))
			|| (!(ft_strncmp(tmp->instr, "sb", 3))
				&& !(ft_strncmp(tmp->next->instr, "sa", 3))))
			tmp = combine_instr(tmp, "ss", list_group);
		else if ((!(ft_strncmp(tmp->instr, "ra", 3))
				&& !(ft_strncmp(tmp->next->instr, "rb", 3)))
			|| (!(ft_strncmp(tmp->instr, "rb", 3))
				&& !(ft_strncmp(tmp->next->instr, "ra", 3))))
			tmp = combine_instr(tmp, "rr", list_group);
		else
			instr_optimization2(&tmp, list_group);
	}
}
