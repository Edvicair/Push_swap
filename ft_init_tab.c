/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:07:49 by edvicair          #+#    #+#             */
/*   Updated: 2021/12/15 00:25:46 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	*tab_cpy(int *src, int size)
{
	int	*cpy;
	int	i;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * size);
	if (!cpy)
		return (0);
	while (i < size)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

int	*ft_init_tab(t_list *a, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * ft_lstsize(a));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = a->nb;
		a = a->next;
		i++;
	}
	return (tab);
}

int	*ft_sort_tab(int *tab, int size)
{
	int		i;
	int		tmp;
	int		*tab2;

	tab2 = tab_cpy(tab, size);
	i = 0;
	while (i + 1 < size)
	{
		if (tab2[i] > tab2[i + 1])
		{
			tmp = tab2[i];
			tab2[i] = tab2[i + 1];
			tab2[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab2);
}

int	ft_max(t_list *a)
{
	int		*tab;
	int		i;
	int		max;

	i = 0;
	tab = ft_init_tab(a, ft_lstsize(a));
	max = tab[i];
	while (i < ft_lstsize(a))
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
