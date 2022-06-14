#include "../push_swap.h"
#include "../../util/ft_printf/src/ft_printf.h"

void	push_a(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b == 0)
		return ;
	while (stacks->size_a > 0)
	{
		stacks->a[stacks->size_a] = stacks->a[stacks->size_a - 1];
		stacks->size_a--;
	}
	stacks->a[0] = stacks->b[0];
	i = 0;
	while (i < stacks->size_b)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
	ft_printf("pa\n");
}

void	push_b(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a == 0)
		return ;
	while (stacks->size_b > 0)
	{
		stacks->b[stacks->size_b] = stacks->b[stacks->size_b - 1];
		stacks->size_b--;
	}
	stacks->b[0] = stacks->a[0];
	i = 0;
	while (i < stacks->size_a)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->size_a--;
	stacks->size_b++;
	ft_printf("pb\n");
}
