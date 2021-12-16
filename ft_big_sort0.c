/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:05:31 by edvicair          #+#    #+#             */
/*   Updated: 2021/12/16 08:30:58 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_quick_ten(t_stack *st, int slice)
{
	t_nb	nb;
	int		size;
	int		*tab;
	int		*tab2;

	size = ft_lstsize(st->a) - slice;
	tab = ft_init_tab(st->a, ft_lstsize(st->a));
	tab2 = ft_sort_tab(tab, ft_lstsize(st->a));
	free(tab);
	while (ft_lstsize(st->a) > size)
	{
		tab = ft_init_tab(st->a, ft_lstsize(st->a));
		nb = ft_tab_end(tab, tab2, ft_lstsize(st->a), slice);
		st = big_rotate_a(st, nb);
		free(tab);
	}
	free(tab2);
	return (st);
}

t_stack	*ft_quick_five(t_stack *st)
{
	int		slice;
	int		count;

	count = 0;
	slice = ft_lstsize(st->a) / 10;
	while (count < 9 && slice != 0)
	{
		st = ft_quick_ten(st, slice);
		count++;
	}
	st = ft_quick_ten(st, ft_lstsize(st->a));
	ft_remoov(st);
	return (st);
}
