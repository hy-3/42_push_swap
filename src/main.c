#include "push_swap.h"

int	errorcheck_and_prep_stack_a(int argc, char *argv[], t_stacks *stacks)
{
	int			i;
	int			k;
	t_int_check	check;
	char		**arg;
	int			num;
	int			j;
	int			l;

	i = 0;
	j = 0;
	while (--argc > 0)
	{
		num = count_num_of_strings(argv[i + 1], ' ');
		arg = ft_split(argv[i + 1], ' ');
		l = 0;
		while (num-- > 0)
		{
			is_int_and_atoi(arg[l], &check);
			if (check.is_int == 0)
				return (1);
			stacks->a[j] = (int) check.res;
			k = 0;
			while (k < j)
			{
				if (stacks->a[k] == check.res)
					return (1);
				k++;
			}
			j++;
			l++;
		}
		i++;
		cust_free(arg);
		free(arg);
	}
	stacks->size_a = j;
	return (0);
}

int	get_max_int(int *stack, int size)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		if (res < stack[i])
			res = stack[i];
		i++;
	}
	return (res);
}

void	move_num_to_b(t_stacks *stacks, int range, int n)
{
	int	i;
	int	tmp;
	int	max_int;

	i = 0;
	tmp = 0;
	max_int = get_max_int(stacks->a, stacks->size_a);
	while (i < stacks->size_a)
	{
		if (stacks->a[i] <= range)
		{
			tmp = stacks->a[i];
			if (i < stacks->size_a / 2)
				while (stacks->a[0] != tmp)
					rotate_a(stacks);
			else
				while (stacks->a[0] != tmp)
					r_rotate_a(stacks);
			push_b(stacks);
			if (n >= 3 && n % 2 != 0)
				rotate_b(stacks);
			i = 0;
			continue ;
		}
		i++;
	}
}

int	get_max_index(int max_int, int *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s[i] == max_int)
			break ;
		i++;
	}
	return (i);
}

void	move_back_to_a(t_stacks *stacks)
{
	int	max_int;
	int	index;

	while (stacks->size_b > 0)
	{
		max_int = get_max_int(stacks->b, stacks->size_b);
		index = get_max_index(max_int, stacks->b, stacks->size_b);
		if (index < stacks->size_b / 2)
			while (stacks->b[0] != max_int)
				rotate_b(stacks);
		else
			while (stacks->b[0] != max_int)
				r_rotate_b(stacks);
		push_a(stacks);
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, &stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks.size_b = 0;

	int	range;
	range = PORTION;
	int max_int = get_max_int(stacks.a, stacks.size_a);
	int n = 1;
	while (range <= max_int)
	{
		move_num_to_b(&stacks, range, n);
		range += PORTION;
		n++;
	}
	move_num_to_b(&stacks, range, n);
	move_back_to_a(&stacks);
	return (0);
}

// to Check.stack a & b.
// int w = 0;
// int size = argc - 1;
// ft_printf("a: \n");
// while(stack.size_a--)
// 	ft_printf("%i ", stack.a[w++]);
// ft_printf("\n");
// ft_printf("b: \n");
// argc = size;
// w = 0;
// while(stack.size_b--)
// 	ft_printf("%i ", stack.b[w++]);
// ft_printf("\n");