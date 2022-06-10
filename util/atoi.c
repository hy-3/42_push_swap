#include "../src/push_swap.h"

t_int_check	*is_int_and_atoi(const char *str, t_int_check *check)
{
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	check->res = 0;
	check->is_integer = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!('0' <= str[i] && str[i] <= '9'))
		check->is_integer = -1;
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		if (check->res * 10 > INT_MAX)
		{
			check->is_integer = -1;
			break ;
		}
		check->res = check->res * 10 + (str[i] - '0');
		if ((check->res == (long long) INT_MAX + 1 || check->res == (long long) INT_MAX + 2) && sign == 1)
		{
			check->is_integer = -1;
			break ;
		}
		if (check->res == (long long) INT_MAX + 2 && sign == -1)
		{
			check->is_integer = -1;
			break ;
		}
		i++;
	}
	if (!('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
		check->is_integer = -1;
	check->res *= sign;
	return (check);
}

//TODO change -1/1 to 0/1