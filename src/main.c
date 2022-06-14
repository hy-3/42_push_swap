#include "push_swap.h"

int	errorcheck_and_prep_stack_a(int argc, char *argv[], t_stack *stack)
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
			stack->a[j] = (int) check.res;
			k = 0;
			while (k < j)
			{
				if (stack->a[k] == check.res)
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
	stack->size_a = j;
	return (0);
}

int	get_max_int(int *s, int size)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < size)
	{
		if (res < s[i])
			res = s[i];
		i++;
	}
	return (res);
}

void	move_num_to_b(t_stack *stack, int range, int n)
{
	int	i;
	int	tmp;
	int	max_int;

	i = 0;
	tmp = 0;
	max_int = get_max_int(stack->a, stack->size_a);
	while (i < stack->size_a)
	{
		if (stack->a[i] <= range)
		{
			tmp = stack->a[i];
			if (i < stack->size_a / 2)
				while (stack->a[0] != tmp)
					rotate_a(stack->a, stack->size_a);
			else
				while (stack->a[0] != tmp)
					r_rotate_a(stack->a, stack->size_a);
			push_b(stack->a, stack->size_a, stack->b, stack->size_b);
			stack->size_a--;
			stack->size_b++;
			if (n >= 3 && n % 2 != 0)
				rotate_b(stack->b, stack->size_b);
			i = 0;
			continue ;
		}
		i++;
	}
}

int	get_max_index(int	max_int, int *s, int size)
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

void	move_back_to_a(t_stack *stack)
{
	int	max_int;
	int	index;

	while (stack->size_b > 0)
	{
		max_int = get_max_int(stack->b, stack->size_b);
		index = get_max_index(max_int, stack->b, stack->size_b);
		if (index < stack->size_b / 2)
			while (stack->b[0] != max_int)
				rotate_b(stack->b, stack->size_b);
		else
			while (stack->b[0] != max_int)
				r_rotate_b(stack->b, stack->size_b);
		push_a(stack->a, stack->size_a, stack->b, stack->size_b);
		stack->size_a++;
		stack->size_b--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, &stack) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack.size_b = 0;

	int	range;
	range = PORTION;
	int max_int = get_max_int(stack.a, stack.size_a);
	int n = 1;
	while (range <= max_int)
	{
		move_num_to_b(&stack, range, n);
		range += PORTION;
		n++;
	}
	move_num_to_b(&stack, range, n);

	move_back_to_a(&stack);

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

	return (0);
}
