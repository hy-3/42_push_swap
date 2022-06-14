#include "../push_swap.h"
#include "../../util/ft_printf/src/ft_printf.h"

void	rotate_a(t_stacks *stacks)
{
	int i;
	int	tmp;

	i = 0;
	tmp = stacks->a[0];
	while (i < (stacks->size_a - 1))
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_stacks *stacks)
{
	int i;
	int	tmp;

	i = 0;
	tmp = stacks->b[0];
	while (i < (stacks->size_b - 1))
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = tmp;
	ft_printf("rb\n");
}

void	rotate_a_and_b(t_stacks *stacks)
{
	int i;
	int	tmp;

	i = 0;
	tmp = stacks->a[0];
	while (i < (stacks->size_a - 1))
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = tmp;
	i = 0;
	tmp = stacks->b[0];
	while (i < (stacks->size_b - 1))
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = tmp;
	ft_printf("rr\n");
}
