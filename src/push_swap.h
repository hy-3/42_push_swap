#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# define PORTION 20

typedef struct s_int_check
{
	int			is_int;
	long long	res;
}	t_int_check;

typedef struct s_stacks
{
	int	a[ARG_MAX];
	int	size_a;
	int	b[ARG_MAX];
	int	size_b;
}	t_stacks;

//	src/operation/swap.c
void	swap_a(t_stacks *stacks);
//	src/operation/push.c
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
//	src/operation/rotate.c
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
//	src/operation/reverse_rotate.c
void	r_rotate_a(t_stacks *stacks);
void	r_rotate_b(t_stacks *stacks);
//	util/atoi.c
void	is_int_and_atoi(const char *str, t_int_check *check);
//	util/str_split.c
char	**ft_split(char const *s, char c);
int		count_num_of_strings(char const *s, char c);
void	cust_free(char **res);

#endif