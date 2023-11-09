/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:40:33 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/21 10:57:13 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_swap *swap)
{
	int	*norm;

	norm = swap->stack_a;
	if (norm[0] > norm[1] && norm[1] < norm[2] && norm[2] > norm[0])
		sa_sb(swap, 0);
	else if (norm[0] < norm[1] && norm[1] > norm[2] && norm[2] < norm[0])
		rra(swap);
	else if (norm[0] > norm[1] && norm[1] < norm[2] && norm[2] < norm[0])
		ra(swap);
	else if (norm[0] > norm[1] && norm[1] > norm[2] && norm[2] < norm[0])
	{
		sa_sb(swap, 0);
		rra(swap);
	}
	else if (norm[0] < norm[1] && norm[1] > norm[2] && norm[2] > norm[0])
	{
		sa_sb(swap, 0);
		ra(swap);
	}
}

void	sort_five(t_swap *swap)
{
	if (is_sorted(swap))
		return ;
	out_min(swap);
	out_min(swap);
	sort_three(swap);
	pa(swap);
	pa(swap);
}

void	radix(t_swap *swap)
{
	int	i;
	int	j;

	j = 0;
	while (!is_sorted(swap))
	{
		i = 0;
		while (i < swap->size)
		{
			if (swap->stack_a[0] >> j & 1)
				ra(swap);
			else
				pb(swap);
			i++;
		}
		while (swap->size_b > 0)
			pa(swap);
		j++;
	}
}
