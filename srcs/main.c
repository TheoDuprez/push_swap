/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:18:40 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/11 17:04:54 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_space(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				count++;
			j++;
		}
		if (count == 0)
			return (FALSE);
		count = 0;
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_error	error;
	t_swap	swap;

	if (!check_space(argc, argv) && argc > 1)
		return (write(2, "Error\n", 6), 1);
	if (!check_error_format(argc, argv, &error))
		return (1);
	error.tab_nb = converter(argv, &error);
	if (!check_duplicate_number(&error))
		return (free(error.tab_nb), 1);
	create_stack(&error, &swap);
	swap.size_b = 0;
	if (swap.size == 2 && swap.stack_a[0] > swap.stack_a[1])
		ra(&swap);
	else if (swap.size == 3)
		sort_three(&swap);
	else if (swap.size == 5)
		sort_five(&swap);
	else
		radix(&swap);
	free(swap.stack_a);
	free(swap.stack_b);
	return (0);
}
