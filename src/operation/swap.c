#include "../push_swap.h"
#include "../../util/ft_printf/src/ft_printf.h"

void	swap_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_a <= 1)
		return ;
	tmp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_b <= 1)
		return ;
	tmp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = tmp;
	ft_printf("sb\n");
}

void	swap_a_and_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
	}
	if (stacks->size_b > 1)
	{
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
	}
	if (stacks->size_a > 1 || stacks->size_b > 1)
		ft_printf("ss\n");
}
