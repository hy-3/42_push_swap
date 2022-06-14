#include "push_swap.h"

int	errorcheck_and_prep_stack_a(int argc, char *argv[], int *a)
{
	int			i;
	int			k;
	t_int_check	check;

	i = 0;
	while (--argc > 0)
	{
		is_int_and_atoi(argv[i + 1], &check);
		if (check.is_int == 0)
			return (1);
		a[i] = (int) check.res;
		k = 0;
		while (k < i)
		{
			if (a[k] == check.res)
				return (1);
			k++;
		}
		i++;
	}
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

	printf("r:%d\n",range);
	i = 0;
	tmp = 0;
	max_int = get_max_int(stack->a, stack->size_a);
	while (i < stack->size_a)
	{
		if (stack->a[i] <= range)
		{
			tmp = stack->a[i];
			printf("tmp: %i\n", tmp);
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
	if (errorcheck_and_prep_stack_a(argc, argv, stack.a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack.size_a = argc - 1;
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
	printf("r:%d\n",range);

	move_back_to_a(&stack);

	// to Check.stack a & b.
	int w = 0;
	int size = argc - 1;
	printf("a: \n");
	while(--argc)
		printf("%i ", stack.a[w++]);
	printf("\n");
	printf("b: \n");
	argc = size;
	w = 0;
	while(argc--)
		printf("%i ", stack.b[w++]);
	printf("\n");

	return (0);
}
