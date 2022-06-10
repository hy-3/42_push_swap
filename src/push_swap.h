#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//TMP
# include <stdio.h>

# include <unistd.h>
# include <limits.h>

typedef struct s_int_check
{
	int			is_int;
	long long	res;
}	t_int_check;

t_int_check	*is_int_and_atoi(const char *str, t_int_check *check);

#endif