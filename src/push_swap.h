#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//TMP
# include <stdio.h>

# include <unistd.h>
# include <limits.h>

# define PORTION 20

typedef struct s_int_check
{
	int			is_int;
	long long	res;
}	t_int_check;

//	src/operation/swap.c
void		swap_a(int *a, int size);
//	src/operation/push.c
void		push_a(int *a, int size_a, int *b, int size_b);
void		push_b(int *a, int size_a, int *b, int size_b);
//	src/operation/rotate.c
void		rotate_a(int *a, int size_a);
//	src/operation/reverse_rotate.c
void	r_rotate_a(int *a, int size_a);
//	util/atoi.c
t_int_check	*is_int_and_atoi(const char *str, t_int_check *check);

#endif