/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:46:52 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/08 19:14:10 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_swap *swap)
{
	int	i;

	i = swap->size_a - 1;
	if (swap->size_b == 0)
		return ;
	swap->size_a++;
	while (i >= 0)
	{
		swap->stack_a[i + 1] = swap->stack_a[i];
		i--;
	}
	swap->stack_a[0] = swap->stack_b[0];
	i = 0;
	swap->size_b -= 1;
	while (i < swap->size_b)
	{
		swap->stack_b[i] = swap->stack_b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_swap *swap)
{
	int	i;

	i = swap->size_b - 1;
	if (swap->size_a == 0)
		return ;
	swap->size_b++;
	while (i >= 0)
	{
		swap->stack_b[i + 1] = swap->stack_b[i];
		i--;
	}
	swap->stack_b[0] = swap->stack_a[0];
	i = 0;
	swap->size_a -= 1;
	while (i < swap->size_a)
	{
		swap->stack_a[i] = swap->stack_a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

void	ra(t_swap *swap)
{
	int	i;
	int	temp;

	i = 0;
	temp = swap->stack_a[0];
	while (i < (swap->size_a - 1))
	{
		swap->stack_a[i] = swap->stack_a[i + 1];
		i++;
	}
	swap->stack_a[i] = temp;
	write(1, "ra\n", 3);
}

void	sa_sb(t_swap *swap, int n)
{
	int	temp;

	if (n == 0)
	{
		if (swap->size_a == 0 || swap->size_a == 1)
			return ;
		temp = swap->stack_a[1];
		swap->stack_a[1] = swap->stack_a[0];
		swap->stack_a[0] = temp;
		write(1, "sa\n", 3);
	}
	else if (n == 1)
	{
		if (swap->size_b == 0 || swap->size_b == 1)
			return ;
		temp = swap->stack_b[1];
		swap->stack_b[1] = swap->stack_b[0];
		swap->stack_b[0] = temp;
		write(1, "sb\n", 3);
	}
}

void	rra(t_swap *swap)
{
	int	i;
	int	temp;

	i = swap->size_a - 1;
	temp = swap->stack_a[i];
	while (i > 0)
	{
		swap->stack_a[i] = swap->stack_a[i - 1];
		i--;
	}
	swap->stack_a[0] = temp;
	write(1, "rra\n", 4);
}
