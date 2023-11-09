/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:15:10 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/09 16:49:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FALSE 0
# define TRUE 1
# define RED "\e[31m"
# include "../libft/includes/libft.h"

// STRUCT //

typedef struct s_error
{
	int			size;
	long int	*tab_nb;
}	t_error;

typedef struct s_swap
{
	int	size;
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_swap;

// Check_error.c && Check_error2.c //

int			get_number_of_int(char *s);
int			check_duplicate_number(t_error *error);
int			check_error_format(int argc, char **argv, t_error *error);

// Convert_char_to_int.c //

long int	*converter(char **argv, t_error *error);

// Create_stack.c //

void		create_stack(t_error *error, t_swap *swap);

// Sort.c //

void		radix(t_swap *swap);
void		sort_five(t_swap *swap);
void		sort_three(t_swap *swap);

// Sort_utils.c //

int			is_sorted(t_swap *swap);
void		out_min(t_swap *swap);

// Swap_functions.c && Swap_functions2.c //

void		pa(t_swap *swap);
void		pb(t_swap *swap);
void		ra(t_swap *swap);
void		rra(t_swap *swap);
void		sa_sb(t_swap *swap, int n);

#endif
