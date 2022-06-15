/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:28 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/15 13:21:29 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../util/ft_printf/src/ft_printf.h"

void	swap_a(int *a, int size_a)
{
	int	tmp;

	if (size_a <= 1)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	ft_printf("sa\n");
}

void	swap_b(int *b, int size_b)
{
	int	tmp;

	if (size_b <= 1)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	ft_printf("sb\n");
}

void	swap_a_and_b(int *a, int size_a, int *b, int size_b)
{
	int	tmp;

	if (size_a > 1)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	if (size_b > 1)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
	if (size_a > 1 || size_b > 1)
		ft_printf("ss\n");
}
