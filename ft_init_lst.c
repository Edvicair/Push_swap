/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:38:16 by edvicair          #+#    #+#             */
/*   Updated: 2021/11/30 09:41:13 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

t_list	*ft_lstnew(int nb)
{
	t_list	*buya;

	buya = (t_list *)malloc(sizeof(t_list));
	if (!buya)
		return (NULL);
	buya->nb = nb;
	buya->next = 0;
	return (buya);
}

t_list	*ft_init(int ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*add_a;

	i = 1;
	if (ac == 0)
	{
		a = NULL;
		return (a);
	}
	a = ft_lstnew(ft_atoi(av[i]));
	i++;
	while (i < ac)
	{
		add_a = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&a, add_a);
		i++;
	}
	return (a);
}
