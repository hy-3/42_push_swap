#include "../../util/ft_printf/src/ft_printf.h"

void	rotate_a(int *a, int size_a)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (i < (size_a - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(int *b, int size_b)
{
	int i;
	int	tmp;

	i = 0;
	tmp = b[0];
	while (i < (size_b - 1))
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = tmp;
	ft_printf("rb\n");
}

void	rotate_a_and_b(int *a, int size_a, int *b, int size_b)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (i < (size_a - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = tmp;
	i = 0;
	tmp = b[0];
	while (i < (size_b - 1))
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = tmp;
	ft_printf("rr\n");
}
