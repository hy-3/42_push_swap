/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:20:50 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 13:13:29 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int j, t_stacks *stacks, t_int_check *check)
{
	int	k;

	k = 0;
	while (k < j)
	{
		if (stacks->a[k] == check->res)
			return (1);
		k++;
	}
	return (0);
}

int	errorcheck_and_prep_stack_a(int argc, char *argv[], t_stacks *stacks)
{
	t_int_check	check;
	char		**arg;
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		arg = ft_split(argv[i], ' ');
		l = -1;
		while (arg[++l] != NULL)
		{
			is_int_and_atoi(arg[l], &check);
			if (check.is_int == 0 || check_duplicate(j, stacks, &check) == 1)
				return (1);
			stacks->a[j++] = (int) check.res;
		}
		cust_free(arg);
		free(arg);
	}
	stacks->size_a = j;
	return (0);
}
