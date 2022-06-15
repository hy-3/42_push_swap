/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:21:46 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/15 13:21:48 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	is_over_int(t_int_check *check, int sign)
{
	if ((check->res > (long long) INT_MAX && sign == 1) || \
		(check->res > (long long) INT_MAX + 1 && sign == -1))
	{
		check->is_int = 0;
		return (1);
	}
	return (0);
}

void	is_int_and_atoi(const char *str, t_int_check *check)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	check->res = 0;
	check->is_int = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!('0' <= str[i] && str[i] <= '9'))
		check->is_int = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		check->res = check->res * 10 + (str[i++] - '0');
		if (is_over_int(check, sign) == 1)
			return ;
	}
	if (str[i] != '\0')
		check->is_int = 0;
	check->res *= sign;
}
