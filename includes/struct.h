/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:02:22 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/14 23:13:12 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_num_list_node
{
	int						num;
	struct s_num_list_node	*prev;
	struct s_num_list_node	*next;
}	t_num_list_node;

typedef struct s_stack_a_and_b
{
	t_num_list_node	*head_a;
	t_num_list_node	*head_b;
}	t_stack_group;
