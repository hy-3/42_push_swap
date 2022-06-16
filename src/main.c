/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:02 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 15:37:03 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(int *stack, int size, t_max *max)
{
	int	i;

	max->num = stack[0];
	max->index = 0;
	i = 1;
	while (i < size)
	{
		if (max->num < stack[i])
		{
			max->num = stack[i];
			max->index = i;
		}
		i++;
	}
}

void	get_second_max(int *stack, int size, t_second_max *second_max, t_max *max)
{
	int	i;

	if (size < 2)
		return ;
	if (stack[0] != max->num)
	{
		second_max->num = stack[0];
		second_max->index = 0;
		i = 1;
	}
	else
	{
		second_max->num = stack[1];
		second_max->index = 1;
		i = 2;
	}
	while (i < size)
	{
		if (second_max->num < stack[i] && stack[i] != max->num)
		{
			second_max->num = stack[i];
			second_max->index = i;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_max		max;

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
	if (stacks.size_a < 4)
		sort_few_num(&stacks, &max);
	else
		sort_more_num(&stacks, &max);
	return (0);
}
