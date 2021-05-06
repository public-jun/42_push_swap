/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:37:46 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/28 16:1 by4 jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	halve_set2(int b_min_count, t_info *info, t_list_group *list_group)
{
	int	push_count;
	t_num_list_node *stack_a;
	t_num_list_node *stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	push_count = 0;
	while (push_count < b_min_count)
	{
		exec_s_r_and_add_instr_node(exec_rr, stack_b, "rrb", list_group, info);
		exec_p_and_add_instr_node(stack_b, stack_a, "pa", list_group, info);
		push_count++;
	}
	while (push_count)
	{
		exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", list_group, info);
		push_count--;
	}
	while (stack_b->prev->num == info->want)
	{
		exec_s_r_and_add_instr_node(exec_rr, stack_b, "rrb", list_group, info);
		exec_p_and_add_instr_node(stack_b, stack_a, "pa", list_group, info);
		exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", list_group, info);
	}
}

void	halve_set(t_info *info, t_list_group *list_group)
{
	t_num_list_node *tmp;
	int		pivot;
	int		b_min_count;

	tmp = list_group->stack_a->next;
	pivot = info->all_size / 2;
	add_front_pivot_list(pivot, list_group, info);
	b_min_count = 0;
	while (info->b_size != pivot)
	{
		if (tmp->num < pivot)
		{
			exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
			if (list_group->stack_b->next->num == b_min_count)
			{
				exec_s_r_and_add_instr_node(exec_r, list_group->stack_b, "rb", list_group, info);
				b_min_count++;
			}
		}
		else
			exec_s_r_and_add_instr_node(exec_r, list_group->stack_a, "ra", list_group, info);
		tmp = list_group->stack_a->next;
	}
	halve_set2(b_min_count, info, list_group);
}

t_pivot	*make_new_pivot(t_list_group *list_group, t_info *info, int pivot)
{
	t_pivot	*res;

	res = (t_pivot *)malloc(sizeof(t_pivot));
	if (!res)
		ft_put_error_and_ps_exit(list_group, info);
	res->p_value = pivot;
	return (res);

}

void	pivot_init(t_info *info, t_list_group *list_group)
{
	info->p_head = make_new_pivot(list_group, info, 0);
	info->p_head->prev = info->p_head;
	info->p_head->next = info->p_head;
}

void	add_front_pivot_list(int pivot, t_list_group *list_group, t_info *info)
{
	t_pivot		*new_node;
	t_pivot		*head;

	head = info->p_head;
	new_node = make_new_pivot(list_group, info, pivot);
	new_node->next = head->next;
	new_node->prev = head;
	head->next->prev = new_node;
	head->next = new_node;
}

void	serch_want(t_list_group *list_group, t_info *info)
{
	t_num_list_node *stack_a;
	t_num_list_node *stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	while ((stack_a->next->num == info->want
		|| stack_a->next->next->num == info->want
		|| stack_b->next->num == info->want
		|| stack_b->next->next->num == info->want
		|| stack_b->prev->num == info->want)
		&& info->want != info->all_size)
	{
		if (stack_a->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", list_group, info);
		else if (stack_b->next->num == info->want)
			exec_p_and_add_instr_node(stack_b, stack_a, "pa", list_group, info);
		else if (stack_b->next->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_s, stack_b, "sb", list_group, info);
		else if (stack_b->prev->num == info->want)
			exec_s_r_and_add_instr_node(exec_rr, stack_b, "rrb", list_group, info);
		else if (stack_a->next->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa", list_group, info);
	}
}

void	b_quick_sort(t_list_group *list_group, t_info *info)
{
	int	pivot;
	t_num_list_node *end;

	//pivot を求める
	pivot = (info->b_size / 2) + info->want;
	end = NULL;
	add_front_pivot_list(pivot, list_group, info);
	while (list_group->stack_b->next != end && info->b_size > 0 && list_group->stack_a->prev != end)
	{
		//want の場合 pa してra
		if (list_group->stack_b->next->num == info->want)
		{
			exec_p_and_add_instr_node(list_group->stack_b, list_group->stack_a, "pa", list_group, info);
			exec_s_r_and_add_instr_node(exec_r, list_group->stack_a, "ra", list_group, info);
		}
		//pivot 以上は pa
		else if (list_group->stack_b->next->num >= pivot)
			exec_p_and_add_instr_node(list_group->stack_b, list_group->stack_a, "pa", list_group, info);
		//pivot より小さいくwantではない
		else
		{
			if (!end)
				end = list_group->stack_b->next;
			exec_s_r_and_add_instr_node(exec_r, list_group->stack_b, "rb", list_group, info);
		}
	}
	serch_want(list_group, info);
	// while (list_group->stack_a->next->num == info->want || list_group->stack_a->next->next->num == info->want)
	// {
	// 	if (list_group->stack_a->next->num == info->want)
	// 		exec_s_r_and_add_instr_node(exec_r, list_group->stack_a, "ra", list_group, info);
	// 	else
	// 	{
	// 		exec_s_r_and_add_instr_node(exec_s, list_group->stack_a, "sa", list_group, info);
	// 		exec_s_r_and_add_instr_node(exec_r, list_group->stack_a, "ra", list_group, info);
	// 	}
	// }
}


/*
** pivot以下をbにpushする
** その際ソートする
*/
void	pb_less_than_pivot(t_list_group *group, t_info *info)
{
	int		pivot;
	t_num_list_node *stack_a;
	t_num_list_node *stack_b;

	pivot = info->p_head->next->p_value;
	stack_a = group->stack_a;
	stack_b = group->stack_b;
	//pivot以下を全てpushするまで
	while (stack_a->next->num <= pivot || stack_a->next->num == info->want || stack_a->next->next->num == info->want || stack_b->next->num == info->want || stack_b->next->num == info->want || stack_a->next->num != 0 )
	{
		//want を探す
		//stack_aの一番上がwant
		if (stack_a->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_r, stack_a, "ra", group, info);
		//stack_aの二番目がwant
		else if (stack_a->next->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_s, stack_a, "sa", group, info);
		//stack_bの一番上がwant
		else if (stack_b->next->num == info->want)
			exec_p_and_add_instr_node(stack_b, stack_a, "pa", group, info);
		//stack_bの二番目がwant
		else if (stack_b->next->next->num == info->want)
			exec_s_r_and_add_instr_node(exec_s, stack_b, "sb", group, info);
		//pivot以下をbにpush
		else
			exec_p_and_add_instr_node(stack_a, stack_b, "pb", group, info);
	}
}

void	sort_remain_node(t_list_group *group, t_info *info)
{
	int	min;

	//残りの要素を全てpush
	while (group->stack_b->next != group->stack_b)
	{
		if (info->b_size > 1)
		{
			min = find_min_value(group->stack_b);
			min_move_top(group->stack_b, min, info, group, info->b_size);
		}
		exec_p_and_add_instr_node(group->stack_b, group->stack_a, "pa", group, info);
		exec_s_r_and_add_instr_node(exec_r, group->stack_a, "ra", group, info);
	}
	serch_want(group, info);
}

int		count_pivot_node(t_info *info)
{
	t_pivot	*tmp;
	int		count;

	tmp = info->p_head->next;
	count = 0;
	while (tmp != info->p_head)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	sort_wrap(t_list_group *list_group, t_info *info)
{
	t_num_list_node *stack_a;
	t_num_list_node *stack_b;

	stack_a = list_group->stack_a;
	stack_b = list_group->stack_b;
	while (stack_a->next->num != 0)
	{
		if (stack_a->next->num != 0)
			exec_p_and_add_instr_node(stack_a, stack_b, "pb", list_group, info);
		serch_want(list_group, info);
	}
}

void	sort_over5(t_list_group *list_group, t_info *info)
{
	pivot_init(info, list_group);
	//pivotより小さいものは b 大きいものは aにpushする
	info->b_min = info->want;
	halve_set(info, list_group);
	/*
	** after half
	*/
	// printf("|%*s    |%*s    |\n", 10, "stack_a", 10, "stack_b");
	t_num_list_node *tmp_a;
	t_num_list_node *tmp_b;
	// tmp_a = list_group->stack_a->next;
	// tmp_b = list_group->stack_b->next;
	// while (tmp_a != list_group->stack_a || tmp_b != list_group->stack_b)
	// {
	// 	if (tmp_a != list_group->stack_a)
	// 	{
	// 		printf("|[%d] %*d", tmp_a->num, -10, info->def[tmp_a->num]);
	// 		fflush(stdout);
	// 		tmp_a = tmp_a->next;
	// 	}
	// 	printf("|");
	// 	if (tmp_b != list_group->stack_b)
	// 	{
	// 		printf("[%d] %*d|", tmp_b->num, -10, info->def[tmp_b->num]);
	// 		tmp_b = tmp_b->next;
	// 	}
	// 	printf("\n");
	// }
	int	tmp_pivot;
	tmp_pivot = 0;
	while (info->want != info->all_size)
	{
		while (info->b_size > 4)
			b_quick_sort(list_group, info);
		if (info->b_size)
			sort_remain_node(list_group, info);
		if (info->want == info->all_size)
			break;
		/*
		** pb を行う部分
		** pivot が複数ある場合 b_size が 3 以上になるまでpushを繰り返す。
		** もしくはpivotが1になるまで
		*/

		/*
		** if (want == info->p_head->next->p_value)
		** tmp_pivot == info->p_head->next->next->p_value
		** tmp_pivot より小さい数をpbする
		*/
		if (count_pivot_node(info) > 1  && info->want == info->p_head->next->p_value)
		{
			tmp_pivot = info->p_head->next->next->p_value;
			while (list_group->stack_a->next->num < tmp_pivot && info->want != info->all_size)
			{
				exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
				serch_want(list_group, info);
			}
		}
		else if (count_pivot_node(info) > 0 && info->want < info->p_head->next->p_value)
		{
			tmp_pivot = info->p_head->next->p_value;
			while (list_group->stack_a->next->num < tmp_pivot && info->want != info->all_size)
			{
				exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
				serch_want(list_group, info);
			}
		}
		else
			 sort_wrap(list_group, info);
		// want < info->p_head->next->p_value
		// sort_wrap(list_group, info);
		info->b_min = info->want;
	}
	printf("\n-----after_sort------\n");
	printf("|%*s    |%*s    |\n", 10, "stack_a", 10, "stack_b");
	tmp_a = list_group->stack_a->next;
	tmp_b = list_group->stack_b->next;
	while (tmp_a != list_group->stack_a || tmp_b != list_group->stack_b)
	{
		if (tmp_a != list_group->stack_a)
		{
			printf("|[%d] %*d", tmp_a->num, -10, info->def[tmp_a->num]);
			fflush(stdout);
			tmp_a = tmp_a->next;
		}
		printf("|");
		if (tmp_b != list_group->stack_b)
		{
			printf("[%d] %*d|", tmp_b->num, -10, info->def[tmp_b->num]);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	// while (info->want != info->all_size)
	// {
	// 	/*
	// 	** bを半分にする
	// 	** pivot を記録する
	// 	** b に残ったノード数を返す
	// 	*/
	// 	while (info->b_size > 3)
	// 		b_quick_sort(list_group, info);
	// 	//残った要素を小さい順にaにpush する
	// 	if (info->b_size)
	// 		sort_remain_node(list_group, info);
	// 	//一番小さいpivot未満が存在していればbにpush その際ソートを行う
	// 	if (info->want < info->p_head->next->p_value)
	// 		pb_less_than_pivot(list_group, info);
	// 	//半分まで到達していたらpivotは存在しないのでa をbに半分pushする
	// 	else if (info->want >= info->p_head->next->p_value)
	// 	{
	// 		info->b_min = info->want;
	// 		halve_set(info, list_group);
	// 	}
	// 	//存在してなければ次のpivotまでをbにpushして上に戻る
	// 	// else if (info->want == info->p_head->next->p_value)
	// 	// {
	// 	// 	next_pivot(list_group, info);
	// 	// }
	// 	info->b_min = info->want;
	// }
}

		// else if (count_pivot_node(info) > 1)
		// {
		// 	while (info->want < tmp_pivot && list_group->stack_a->next->num != 0)
		// 	{
		// 		if (list_group->stack_a->next->num != 0 && info->want < tmp_pivot)
		// 			exec_p_and_add_instr_node(list_group->stack_a, list_group->stack_b, "pb", list_group, info);
		// 		serch_want(list_group, info, 1);
		// 	}
		// 	if (info->want == info->all_size)
		// 		break;
		// }
		// sort_wrap(list_group, info);
		// info->b_min = info->want;
