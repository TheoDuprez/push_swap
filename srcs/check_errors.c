/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:20:50 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/21 13:46:57 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sign(char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] == '0')
				i++;
			j = i;
			while (s[j] != ' ' && s[j])
				if (s[j] == '-' || s[j++] == '+')
					return (FALSE);
			if (j - i >= 12)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		else if ((s[i] == '-' || s[i] == '+') && \
			(!(s[i + 1] >= '0' && s[i + 1] <= '9')))
			return (FALSE);
	}
	return (TRUE);
}

static int	arg_is_valid(char *s)
{
	int	i;

	i = 0;
	if (!check_sign(s))
		return (FALSE);
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || s[i] == ' ' || s[i] == '-' || s[i] == '+'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_error_format(int argc, char **argv, t_error *error)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit(0);
	error->size = 0;
	while (i < argc)
	{
		error->size += get_number_of_int(argv[i]);
		if (argv[i][0] == 0)
			return (write(2, "Error\n", 6), FALSE);
		if (!arg_is_valid(argv[i]))
			return (write(2, "Error\n", 6), FALSE);
		i++;
	}
	return (TRUE);
}

int	get_number_of_int(char *s)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') || (s[i] >= '0' && s[i] <= '9'))
		{
			while (s[i] != ' ' && s[i])
				i++;
			size++;
		}
		if (s[i] == 0)
			break ;
		i++;
	}
	return (size);
}

int	check_duplicate_number(t_error *error)
{
	int			i;
	int			j;
	long int	temp;

	i = 0;
	while (i < error->size)
	{
		j = i + 1;
		temp = error->tab_nb[i];
		if (temp < 0)
		{
			temp = temp * -1;
			if (temp > 2147483648)
				return (write(2, "Error\n", 6), FALSE);
			temp *= -1;
		}
		else if (temp > 2147483647)
			return (write(2, "Error\n", 6), FALSE);
		while (j < error->size)
			if (error->tab_nb[j++] == error->tab_nb[i])
				return (write(2, "Error\n", 6), FALSE);
		i++;
	}
	return (TRUE);
}
