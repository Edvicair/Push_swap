/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:06:13 by edvicair          #+#    #+#             */
/*   Updated: 2021/12/16 08:31:30 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nb	ft_tab_start(int *tab, int *tab_sort, int size, int slice)
{
	t_nb	nb;
	int		i;
	int		j;

	i = 0;
	nb.start = tab[i];
	nb.start_pos = i;
	while (i < size)
	{
		j = 0;
		while (j < slice)
		{
			if (tab[i] == tab_sort[j])
			{
				nb.start_pos = i;
				nb.start = tab[i];
				return (nb);
			}
			j++;
		}
		i++;
	}
	return (nb);
}

t_nb	ft_tab_end(int *tab, int *tab_sort, int size, int slice)
{
	t_nb	nb;
	int		j;

	j = 0;
	nb = ft_tab_start(tab, tab_sort, size, slice);
	nb.end = tab[--size];
	nb.end_pos = size;
	while (size > 0)
	{
		j = 0;
		while (j < slice)
		{
			if (tab[size] == tab_sort[j])
			{
				nb.end_pos = size;
				nb.end = tab[size];
				return (nb);
			}
			j++;
		}
		size--;
	}
	return (nb);
}

t_stack	*big_rotate_a(t_stack *st, t_nb nb)
{
	int		rotate;

	rotate = ft_lstsize(st->a) - nb.end_pos;
	if (nb.start_pos <= rotate)
	{
		while (nb.start_pos > 0)
		{
			ft_write_algo("ra\n", st);
			nb.start_pos--;
		}
	}
	else
	{
		while (rotate > 0)
		{
			ft_write_algo1("rra\n", st);
			rotate--;
		}
	}
	ft_write_algo1("pb\n", st);
	return (st);
}

t_stack	*big_rotate_b(t_stack *st, int i, int size)
{
	int		nb;

	if (i <= size)
	{
		while (i > 0)
		{
			ft_write_algo("rb\n", st);
			i--;
		}
	}
	else
	{
		nb = ft_lstsize(st->b) - i;
		while (nb > 0)
		{
			ft_write_algo1("rrb\n", st);
			nb--;
		}
	}
	ft_write_algo1("pa\n", st);
	return (st);
}

t_stack	*ft_remoov(t_stack *st)
{
	int		*tab;
	int		i;
	int		max;

	while ((ft_lstsize(st->b)) >= 1)
	{
		i = 0;
		tab = ft_init_tab(st->b, ft_lstsize(st->b));
		max = ft_max(st->b);
		while (tab[i] != max)
			i++;
		st = big_rotate_b(st, i, ((ft_lstsize(st->b)) / 2));
		free(tab);
	}
	return (st);
}
