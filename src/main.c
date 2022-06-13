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

int	get_max_int(int *a, int size_a)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	printf("size_a:%i\n", size_a);
	while (i < size_a)
	{
		if (res < a[i])
			res = a[i];
		printf("res:%i\n", res);
		
		i++;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	int	a[ARG_MAX];
	int	size_a;
	int	b[ARG_MAX];
	int	size_b;
	int	max_int;

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, a) == 1)
		write(2, "Error\n", 6);
	size_a = argc - 1;
	size_b = 0;
	while (PORTION)

	// move first 20% to stack B.
	int	i = 0;
	int tmp = 0;
	max_int = get_max_int(a, size_a);
	printf("max:%i\n", max_int);
	while (i < size_a)
	{
		if (a[i] < max_int * ((double) PORTION / (double) 100))
		{
			tmp = a[i];
			if (i < size_a / 2)
				while (a[0] != tmp)
					rotate_a(a, size_a);
			else
				while (a[0] != tmp)
					r_rotate_a(a, size_a);
			push_b(a, size_a, b, size_b);
			size_a--;
			size_b++;
			i = 0;
		}
		i++;
	}

	// to Check.stack a & b.
	int n = 0;
	int size = argc - 1;
	printf("a: \n");
	while(--argc)
		printf("%i ", a[n++]);
	printf("\n");
	printf("b: \n");
	argc = size;
	n = 0;
	while(argc--)
		printf("%i ", b[n++]);
	printf("\n");
	// int i = 0;
	// int size = argc - 1;
	// printf("first\n");
	// while(--argc)
	// 	printf("%i ", a[i++]);
	// printf("\n");
	// b[0] = 33;
	// b[1] = 34;
	// b[2] = 35;
	// r_rotate_a(a, size);
	// printf("second a\n");
	// argc = size;
	// i = 0;
	// while(argc--)
	// 	printf("%i ", a[i++]);
	// printf("\n");

	return (0);
}
