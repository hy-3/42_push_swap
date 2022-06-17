/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:52:46 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 20:18:07 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_stacks *stacks, int range)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] <= range)
		{
			tmp = stacks->a[i];
			if (i < (stacks->size_a / 2))
				while (stacks->a[0] != tmp)
					rotate_a(stacks->a, stacks->size_a);
			else
				while (stacks->a[0] != tmp)
					r_rotate_a(stacks->a, stacks->size_a);
			push_b(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
			stacks->size_a--;
			stacks->size_b++;
			i = 0;
		}
		else
			i++;
	}
}

void	move_back_to_a(t_stacks *stacks)
{
	t_max			max;
	t_second_max	second_max;

	while (stacks->size_b > 0)
	{
		get_max(stacks->b, stacks->size_b, &max);
		get_second_max(stacks->b, stacks->size_b, &second_max, &max);
		if (max.index < (stacks->size_b / 2))
		{
			while (stacks->b[0] != max.num)
			{
				if (stacks->b[0] == second_max.num)
				{
					push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
					stacks->size_a++;
					stacks->size_b--;
				}
				else
					rotate_b(stacks->b, stacks->size_b);
			}
		}
		else
		{
			while (stacks->b[0] != max.num)
			{
				if (stacks->b[0] == second_max.num)
				{
					push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
					stacks->size_a++;
					stacks->size_b--;
				}
				else
					r_rotate_b(stacks->b, stacks->size_b);
			}
		}
		push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
		stacks->size_a++;
		stacks->size_b--;
		if (stacks->size_a >= 2)
			if (stacks->a[0] > stacks->a[1])
				swap_a(stacks->a, stacks->size_a);
	}
}

void	sort_more_num(t_stacks *stacks)
{
	int		range;
	t_max	max;

	get_max(stacks->a, stacks->size_a, &max);
	range = max.num * 0.09;
	if (max.num < 12)
		move_to_b(stacks, 12);
	else
	{
		while (range <= max.num)
		{
			move_to_b(stacks, range);
			range += max.num * 0.09;
		}
		move_to_b(stacks, range);
	}
	move_back_to_a(stacks);
}
