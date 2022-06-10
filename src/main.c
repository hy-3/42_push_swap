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

int	main(int argc, char *argv[])
{
	int	a[ARG_MAX];
	int	b[ARG_MAX];

	if (argc == 1)
		return (0);
	if (errorcheck_and_prep_stack_a(argc, argv, a) == 1)
		write(2, "Error\n", 6);
	
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
