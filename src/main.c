/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:02 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 13:49:43 by hiyamamo         ###   ########.fr       */
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
