/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char_to_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:24:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/03/21 13:01:44 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	nb_char(char **argv)
{
	int	i;
	int	j;
	int	nb_char;

	j = 1;
	nb_char = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			i++;
			nb_char++;
		}
		j++;
		nb_char++;
	}
	return (nb_char);
}

static char	**put_arg_in_tab(char **argv, int size)
{
	char	**tab_nb;
	char	*args;
	int		i;
	int		j;
	int		k;

	j = 1;
	k = 0;
	args = malloc(sizeof(char) * (size + 1));
	if (!args)
		exit(1);
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
			args[k++] = argv[j][i++];
		args[k++] = ' ';
		j++;
	}
	args[k] = 0;
	tab_nb = ft_split(args, ' ');
	free(args);
	if (!tab_nb)
		exit(1);
	return (tab_nb);
}

static long int	*convert_tab_char_to_int(char **tab_nb, t_error *error)
{
	long int	*tab;
	int			j;

	j = 0;
	tab = malloc(sizeof(long int) * error->size);
	if (!tab)
	{
		free_str_arr(1, tab_nb);
		exit(1);
	}
	while (tab_nb[j])
	{
		tab[j] = ft_atoi(tab_nb[j]);
		j++;
	}
	return (tab);
}

long int	*converter(char **argv, t_error *error)
{
	char			**tab_nb;
	int				size;
	long int		*res;

	size = nb_char(argv);
	tab_nb = put_arg_in_tab(argv, size);
	res = convert_tab_char_to_int(tab_nb, error);
	free_str_arr(1, tab_nb);
	return (res);
}
