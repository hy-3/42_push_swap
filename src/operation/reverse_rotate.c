#include "../push_swap.h"
#include "../../util/ft_printf/src/ft_printf.h"

void	r_rotate_a(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a[stacks->size_a - 1];
	while (--(stacks->size_a) > 0)
		stacks->a[stacks->size_a] = stacks->a[stacks->size_a - 1];
	stacks->a[0] = tmp;
	ft_printf("rra\n");
}

void	r_rotate_b(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b[stacks->size_b - 1];
	while (--(stacks->size_b) > 0)
		stacks->b[stacks->size_b] = stacks->b[stacks->size_b - 1];
	stacks->b[0] = tmp;
	ft_printf("rrb\n");
}

void	r_rotate_a_and_b(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a[stacks->size_a - 1];
	while (--(stacks->size_a) > 0)
		stacks->a[stacks->size_a] = stacks->a[stacks->size_a - 1];
	stacks->a[0] = tmp;
	tmp = stacks->b[stacks->size_b - 1];
	while (--(stacks->size_b) > 0)
		stacks->b[stacks->size_b] = stacks->b[stacks->size_b - 1];
	stacks->b[0] = tmp;
	ft_printf("rrr\n");
}
