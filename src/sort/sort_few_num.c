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

void	sort_three(t_stacks *stacks, t_max *max)
{
	if (max->index == 0)
	{
		if (stacks->a[1] < stacks->a[2])
			rotate_a(stacks->a, stacks->size_a);
		else
		{
			rotate_a(stacks->a, stacks->size_a);
			swap_a(stacks->a, stacks->size_a);
		}
	}
	else if (max->index == 1)
	{
		if (stacks->a[0] > stacks->a[2])
			r_rotate_a(stacks->a, stacks->size_a);
		else
		{
			r_rotate_a(stacks->a, stacks->size_a);
			swap_a(stacks->a, stacks->size_a);
		}
	}
	else if (max->index == 2)
		swap_a(stacks->a, stacks->size_a);
}

void	sort_few_num(t_stacks *stacks, t_max *max)
{
	if (stacks->size_a == 2)
		swap_a(stacks->a, stacks->size_a);
	else
		sort_three(stacks, max);
}
