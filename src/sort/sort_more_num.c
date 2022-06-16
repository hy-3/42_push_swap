/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:52:46 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 13:52:49 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_stacks *stacks, int range, int n)
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
			if (n >= 3 && n % 2 != 0)
				rotate_b(stacks->b, stacks->size_b);
			i = 0;
		}
		else
			i++;
	}
}

void	move_back_to_a(t_stacks *stacks)
{
	t_max	max;

	while (stacks->size_b > 0)
	{
		get_max(stacks->b, stacks->size_b, &max);
		if (max.index < (stacks->size_b / 2))
			while (stacks->b[0] != max.num)
				rotate_b(stacks->b, stacks->size_b);
		else
			while (stacks->b[0] != max.num)
				r_rotate_b(stacks->b, stacks->size_b);
		push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
		stacks->size_a++;
		stacks->size_b--;
	}
}

void	sort_more_num(t_stacks *stacks, t_max *max)
{
	int	range;
	int	n;

	range = max->num * 0.1;
	if (max->num < 10)
		move_to_b(stacks, 10, 1);
	else
	{
		n = 1;
		while (range <= max->num)
		{
			move_to_b(stacks, range, n);
			range += max->num * 0.1;
			n++;
		}
		move_to_b(stacks, range, n);
	}
	move_back_to_a(stacks);
}
