/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/25 15:04:21 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_num_list_node
{
	int						num;
	int						index;
	struct s_num_list_node	*prev;
	struct s_num_list_node	*next;
}	t_num_list_node;

typedef struct s_instruction_list_node
{
	char						*instr;
	struct s_instruction_list_node	*prev;
	struct s_instruction_list_node	*next;
}	t_instr_list_node;

typedef struct s_list_group
{
	t_num_list_node	*stack_a;
	t_num_list_node	*stack_b;
	t_instr_list_node *head_instr;
}	t_list_group;
#endif
