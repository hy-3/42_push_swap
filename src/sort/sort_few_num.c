/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:52:40 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 13:52:42 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stacks *stacks)
{
	t_max	max;

	get_max(stacks->a, stacks->size_a, &max);
	if (max.index == 0)
	{
		if (stacks->a[1] < stacks->a[2])
			rotate_a(stacks->a, stacks->size_a);
		else
		{
			rotate_a(stacks->a, stacks->size_a);
			swap_a(stacks->a, stacks->size_a);
		}
	}
	else if (max.index == 1)
	{
		if (stacks->a[0] > stacks->a[2])
			r_rotate_a(stacks->a, stacks->size_a);
		else
		{
			r_rotate_a(stacks->a, stacks->size_a);
			swap_a(stacks->a, stacks->size_a);
		}
	}
	else if (max.index == 2)
		swap_a(stacks->a, stacks->size_a);
}

void	sort_four(t_stacks *stacks)
{
	t_min	min;

	get_min(stacks->a, stacks->size_a, &min);
	if (min.index < 2)
		while (stacks->a[0] != min.num)
			rotate_a(stacks->a, stacks->size_a);
	else
		while (stacks->a[0] != min.num)
			r_rotate_a(stacks->a, stacks->size_a);
	push_b(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
	stacks->size_a--;
	stacks->size_b++;
	sort_three(stacks);
	push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
	stacks->size_a++;
	stacks->size_b--;
}

void	sort_five(t_stacks *stacks)
{
	t_min	min;

	get_min(stacks->a, stacks->size_a, &min);
	if (min.index < 2)
		while (stacks->a[0] != min.num)
			rotate_a(stacks->a, stacks->size_a);
	else
		while (stacks->a[0] != min.num)
			r_rotate_a(stacks->a, stacks->size_a);
	push_b(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
	stacks->size_a--;
	stacks->size_b++;
	sort_four(stacks);
	push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
	stacks->size_a++;
	stacks->size_b--;
}

void	sort_few_num(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		swap_a(stacks->a, stacks->size_a);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	else
		sort_five(stacks);
}
