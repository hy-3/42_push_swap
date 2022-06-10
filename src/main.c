#include "push_swap.h"

int	errorcheck_args(int argc, char *argv[], int *a)
{
	int 		i;
	int 		k;
	t_int_check	check;

	i = 0;
	while(--argc > 0)
	{
		// is int?, over int?
		is_int_and_atoi(argv[i + 1], &check);
		if (check.is_integer == -1)
			return (-1);
		else
			a[i] = (int) check.res;

		// is dupulicate
		k = 0;
		while (k < i)
		{
			if (a[k] == check.res)
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}
//TODO change -1/1 to 0/1

int	main(int argc, char *argv[])
{
	int	a[ARG_MAX];
	int	b[ARG_MAX];

	if (argc == 1)
		return (0);
	if (errorcheck_args(argc, argv, a) == -1)
		write(2, "Error\n", 6);
	return (0);
}