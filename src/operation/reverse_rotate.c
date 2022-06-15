/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:16 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/15 13:21:19 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../util/ft_printf/src/ft_printf.h"

void	r_rotate_a(int *a, int size_a)
{
	int	tmp;

	tmp = a[size_a - 1];
	while (--size_a > 0)
		a[size_a] = a[size_a - 1];
	a[0] = tmp;
	ft_printf("rra\n");
}

void	r_rotate_b(int *b, int size_b)
{
	int	tmp;

	tmp = b[size_b - 1];
	while (--size_b > 0)
		b[size_b] = b[size_b - 1];
	b[0] = tmp;
	ft_printf("rrb\n");
}

void	r_rotate_a_and_b(int *a, int size_a, int *b, int size_b)
{
	int	tmp;

	tmp = a[size_a - 1];
	while (--size_a > 0)
		a[size_a] = a[size_a - 1];
	a[0] = tmp;
	tmp = b[size_b - 1];
	while (--size_b > 0)
		b[size_b] = b[size_b - 1];
	b[0] = tmp;
	ft_printf("rrr\n");
}
