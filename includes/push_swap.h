/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/07 14:22:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ALPHA		1
# define BRAVO		2
# define COMBINED	3

# define UP			1
# define DOWN		2

# define CLOCK		1
# define REVERSE	2

typedef struct s_data
{
	int				i;
	int				*nums;
	int				stack_size;
	int				counter;
	struct s_stack	*pile_a;
	struct s_stack	*pile_b;
	int				is_sorted;
}					t_data;

typedef struct s_stack
{
	int				num;
	int				sorted_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* ACTIONS */

/* actions_1.c */
int			sab(t_stack **pile, int a_or_b, t_data *data);
int			ss(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			pa(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			pb(t_stack **pile_a, t_stack **pile_b, t_data *data);
/* actions_2.c */
int			rab(t_stack **stack, int a_or_b, t_data *data);
int			rr(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			rrab(t_stack **stack, int a_or_b, t_data *data);
int			rrr(t_stack **pile_a, t_stack **pile_b, t_data *data);

/* ALGOS */

/* algo_big_nbrs_1.c */
void		algo_big_nums(t_data *data);
/* algo_big_nbrs_2.c */
void		add_sorted_positions(t_data *data, t_stack *pile_a);
int			organize_pile_bravo(t_data *data);
void		empty_pile_bravo(t_data *data);
/* algo_big_nums_3.c */

/*algo_case_2.c*/
void		algo_case_two_nums(t_data *data);
/* algo_case_3.c */
void		algo_case_three_nums(t_data *data, int *nums);
/* algo_case_4.c */
void		algo_case_four_nums(t_data *data);
/* algo_case_5.c*/
void		algo_case_five_nums(t_data *data);

/* ARGS PROCESSING */

/* check_args_validity_1.c */
int			*check_args_are_valid(char **input, t_data *data);
/* check_args_validity_2.c */
int			check_if_already_sorted(int *nums, int stack_size);
int			check_if_duplicates(int	*nums, int stack_size);
int			is_int_compatible(const char *str);
/* format_input.c */
char		**format_input(int argc, char **argv, t_data *data);

/* STACKS */

/* manage_piles.c */
int			calc_pile_size(t_stack *pile);
int			distance_to_top_pile(int value, t_stack *pile);
void		push_to_top_pile(t_data *data, int num, int pile_id);
int			distance_from_sorted_pos(int value, t_stack *pile);
t_stack		*create_pile_a(int *nums, int size_of_stack);
/* stack_utils_1.c */
void		stack_delone(t_stack **stack);
void		stack_clear(t_stack **stack);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_add_back(t_stack **stack, t_stack *new);
/* stack_utils_2.c */
t_stack		*stack_last(t_stack *stack);
t_stack		*stack_penultimate(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int nb);

/* UTILS */

/* algo_utils.c */
void		sort_param_top_b(t_data *data, int *nums, int num_len);
int			*pile_to_int_arr(t_stack *pile);
/* free.c */
void		error_and_exit(t_data *data);
void		free_stacks_and_exit(t_data *data);
void		suppress_leaks_bfr_exit(t_data *data);
void		free_split(char **split);
/* interval.c */
int			*find_interval(t_stack *pile);
/* quicksort.c */
int			*int_arr_dup(int *to_cpy, int arr_size);
int			are_arr_equals(int *arr_a, int *arr_b, int arr_size);
void		quicksort(int *nums, int begin, int end);

/* FILE CONTAINING MAIN */

/* push_swap.c */
void		msg_writer(int fildes, char *msg, t_data *data);

#endif
