/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:02 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 13:19:07 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(int *stack, int size, t_max *max)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			max->num = stack[i];
		if (max->num < stack[i])
		{
			max->num = stack[i];
			max->index = i;
		}
		i++;
	}
}

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

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_max		max;
	int			range;
	int			n;

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, &stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (stacks.size_a == 1 || check_sorted(stacks.a, stacks.size_a) == 1)
		return (0);
	stacks.size_b = 0;
	get_max(stacks.a, stacks.size_a, &max);
	range = max.num * 0.1;
	if (max.num < 10)
		move_to_b(&stacks, 10, 1);
	else
	{
		n = 1;
		while (range <= max.num)
		{
			move_to_b(&stacks, range, n);
			range += max.num * 0.1;
			n++;
		}
		move_to_b(&stacks, range, n);
	}
	move_back_to_a(&stacks);
	return (0);
}
