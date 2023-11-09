/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:39:52 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/21 13:00:13 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	make_index(t_error *error, t_swap *swap, int *tab)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < swap->size)
	{
		tab[i] = (int)error->tab_nb[i];
		i++;
	}
	i = 0;
	while (i < swap->size)
	{
		j = 0;
		while (j < swap->size)
		{
			if (tab[i] > tab[j])
				index++;
			j++;
		}
		swap->stack_a[i] = index;
		i++;
		index = 0;
	}
}

static void	convert_long_to_index(t_error *error, t_swap *swap)
{
	int	*tab;

	swap->stack_a = malloc(sizeof(int) * error->size);
	if (!swap->stack_a)
	{
		free(error->tab_nb);
		exit(1);
	}
	tab = malloc(sizeof(int) * error->size);
	if (!tab)
	{
		free(error->tab_nb);
		free(swap->stack_a);
		exit(1);
	}
	make_index(error, swap, tab);
	free(tab);
	free(error->tab_nb);
}

void	create_stack(t_error *error, t_swap *swap)
{
	swap->size = error->size;
	convert_long_to_index(error, swap);
	swap->stack_b = malloc(sizeof(int) * swap->size);
	if (!swap->stack_b)
	{
		free(swap->stack_a);
		exit(1);
	}
	swap->size_a = swap->size;
}
