/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:22:12 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/06/16 18:40:34 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//TODO: delete
#include <stdio.h>

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

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

typedef struct s_max
{
	int	num;
	int	index;
}	t_max;

typedef struct s_second_max
{
	int	num;
	int	index;
}	t_second_max;

//	src/main.c
void	get_max(int *stack, int size, t_max *max);
void	get_second_max(int *stack, int size, t_second_max *second_max, t_max *max);
//	src/check.c
int		check_duplicate(int j, t_stacks *stacks, t_int_check *check);
int		errorcheck_and_prep_stack_a(int argc, char *argv[], t_stacks *stacks);
int		check_sorted(int *a, int size_a);
//	src/sort/sort_few_num.c
void	sort_few_num(t_stacks *stacks, t_max *max);
//	src/sort/sort_more_num.c
void	sort_more_num(t_stacks *stacks, t_max *max);
//	src/operation/swap.c
void	swap_a(int *a, int size_a);
//	src/operation/push.c
void	push_a(int *a, int size_a, int *b, int size_b);
void	push_b(int *a, int size_a, int *b, int size_b);
//	src/operation/rotate.c
void	rotate_a(int *a, int size_a);
void	rotate_b(int *b, int size_b);
//	src/operation/reverse_rotate.c
void	r_rotate_a(int *a, int size_a);
void	r_rotate_b(int *b, int size_b);
//	util/atoi.c
void	is_int_and_atoi(const char *str, t_int_check *check);
//	util/str_split.c
char	**ft_split(char const *s, char c);
int		count_num_of_strings(char const *s, char c);
void	cust_free(char **res);

#endif
