#include "../../util/ft_printf/src/ft_printf.h"

void	push_a(int *a, int size_a, int *b, int size_b)
{
	int	i;

	if (size_b == 0)
		return ;
	while (size_a > 0)
	{
		a[size_a] = a[size_a - 1];
		size_a--;
	}
	a[0] = b[0];
	i = 0;
	while (i < size_b)
	{
		b[i] = b[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	push_b(int *a, int size_a, int *b, int size_b)
{
	int	i;

	if (size_a == 0)
		return ;
	while (size_b > 0)
	{
		b[size_b] = b[size_b - 1];
		size_b--;
	}
	b[0] = a[0];
	i = 0;
	while (i < size_a)
	{
		a[i] = a[i + 1];
		i++;
	}
	ft_printf("pb\n");
}
