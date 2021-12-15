/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:19:35 by edvicair          #+#    #+#             */
/*   Updated: 2021/11/30 09:22:22 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_check_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ft_check_double(ac, av) == -1)
		return (-1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && j == 0)
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check(int ac, char **av)
{
	unsigned int	j;
	int				i;
	char			*str;

	i = 1;
	j = 0;
	if (ft_check_digit(ac, av) == -1)
		return (-1);
	while (i < ac)
	{
		str = ft_itoa(ft_atoi(av[i]), j);
		if (ft_strcmp(str, av[i]) != 0)
		{
			free(str);
			return (-1);
		}
		free(str);
		i++;
	}
	return (0);
}
