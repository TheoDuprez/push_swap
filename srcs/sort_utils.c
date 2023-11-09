/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:32:16 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/08 19:14:13 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->size - 1)
	{
		if (swap->stack_a[i] > swap->stack_a[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	get_min_index(t_swap *swap)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < swap->size_a)
	{
		if (swap->stack_a[i] < swap->stack_a[index])
			index = i;
		i++;
	}
	return (index);
}

void	out_min(t_swap *swap)
{
	int	index;

	index = get_min_index(swap);
	if (index == 0)
		pb(swap);
	else if (index == (swap->size_a - 1))
		rra(swap);
	else if (index == 1)
		ra(swap);
	else if (index == 2)
	{
		ra(swap);
		ra(swap);
	}
	else if (index == 3)
	{
		ra(swap);
		ra(swap);
		ra(swap);
	}
	if (index != 0)
		pb(swap);
}
