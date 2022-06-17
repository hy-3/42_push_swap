#include "push_swap.h"

void	get_max(int *stack, int size, t_max *max)
{
	int	i;

	max->num = stack[0];
	max->index = 0;
	i = 1;
	while (i < size)
	{
		if (max->num < stack[i])
		{
			max->num = stack[i];
			max->index = i;
		}
		i++;
	}
}

void	get_second_max(int *stack, int size, t_second_max *second_max, t_max *max)
{
	int	i;

	if (size < 2)
		return ;
	if (stack[0] != max->num)
	{
		second_max->num = stack[0];
		second_max->index = 0;
		i = 1;
	}
	else
	{
		second_max->num = stack[1];
		second_max->index = 1;
		i = 2;
	}
	while (i < size)
	{
		if (second_max->num < stack[i] && stack[i] != max->num)
		{
			second_max->num = stack[i];
			second_max->index = i;
		}
		i++;
	}
}

void	get_min(int *stack, int size, t_min *min)
{
	int	i;

	min->num = stack[0];
	min->index = 0;
	i = 1;
	while (i < size)
	{
		if (min->num > stack[i])
		{
			min->num = stack[i];
			min->index = i;
		}
		i++;
	}
}
