/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/05/08 15:18:26 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define ARGLIMIT 1001

typedef struct s_num_list_node
{
	int						num;
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
	t_num_list_node	*stack_a_test;
	t_num_list_node	*stack_b;
	t_num_list_node	*stack_b_test;
	t_instr_list_node *head_instr;
}	t_list_group;

typedef struct s_pair
{
	int		value;
	int		id;
}	t_pair;

typedef struct s_pivot
{
	int		p_value;
	struct s_pivot	*next;
	struct s_pivot	*prev;
}	t_pivot;

typedef struct s_info
{
	t_pair	n[ARGLIMIT + 10];
	int		def[ARGLIMIT + 10];
	t_pivot	*p_head;
	int		all_size;
	int		a_size;
	int		b_size;
	int		a_min;
	int		b_min;
	int		want;
	int		v_flag;
	int		a_flag;
	int		c_flag;
}	t_info;

#endif
