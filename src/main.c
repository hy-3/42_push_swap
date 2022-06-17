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

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

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
	if (stacks.size_a <= 5)
		sort_few_num(&stacks);
	else
		sort_more_num(&stacks);
	return (0);
}
