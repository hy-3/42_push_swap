#include "push_swap.h"

int	check_duplicate(int	j, t_stacks *stacks, t_int_check *check)
{
	int	k;

	k = 0;
	while (k < j)
	{
		if (stacks->a[k] == check->res)
			return (1);
		k++;
	}
	return (0);
}

int	errorcheck_and_prep_stack_a(int argc, char *argv[], t_stacks *stacks)
{
	t_int_check	check;
	char		**arg;
	int			num;
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		num = count_num_of_strings(argv[i], ' ');
		arg = ft_split(argv[i], ' ');
		l = -1;
		while (num-- > 0)
		{
			is_int_and_atoi(arg[++l], &check);
			if (check.is_int == 0 || check_duplicate(j, stacks, &check) == 1)
				return (1);
			stacks->a[j++] = (int) check.res;
		}
		cust_free(arg);
		free(arg);
	}
	stacks->size_a = j;
	return (0);
}

void	get_max(int *stack, int size, t_max *max)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			max->num = stack[i];
		if (max->num < stack[i])
		{
			max->num = stack[i];
			max->index = i;
		}
		i++;
	}
}

void	move_to_b(t_stacks *stacks, int range, int n)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] <= range)
		{
			tmp = stacks->a[i];
			if (i < (stacks->size_a / 2))
				while (stacks->a[0] != tmp)
					rotate_a(stacks->a, stacks->size_a);
			else
				while (stacks->a[0] != tmp)
					r_rotate_a(stacks->a, stacks->size_a);
			push_b(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
			stacks->size_a--;
			stacks->size_b++;
			if (n >= 3 && n % 2 != 0)
				rotate_b(stacks->b, stacks->size_b);
			i = 0;
			continue ;
		}
		i++;
	}
}

void	move_back_to_a(t_stacks *stacks)
{
	t_max	max;

	while (stacks->size_b > 0)
	{
		get_max(stacks->b, stacks->size_b, &max);
		if (max.index < (stacks->size_b / 2))
			while (stacks->b[0] != max.num)
				rotate_b(stacks->b, stacks->size_b);
		else
			while (stacks->b[0] != max.num)
				r_rotate_b(stacks->b, stacks->size_b);
		push_a(stacks->a, stacks->size_a, stacks->b, stacks->size_b);
		stacks->size_a++;
		stacks->size_b--;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_max		max;
	int			range;
	int			n;

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, &stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks.size_b = 0;
	range = PORTION;
	get_max(stacks.a, stacks.size_a, &max);
	n = 1;
	while (range <= max.num)
	{
		move_to_b(&stacks, range, n);
		range += PORTION;
		n++;
	}
	move_to_b(&stacks, range, n);
	move_back_to_a(&stacks);
	return (0);
}

	// // to Check.stack a & b.
	// int w = 0;
	// printf("a: \n");
	// while(stacks.size_a--)
	// 	printf("%i ", stacks.a[w++]);
	// printf("\n");
	// printf("b: \n");
	// w = 0;
	// while(stacks.size_b--)
	// 	printf("%i ", stacks.b[w++]);
	// printf("\n");