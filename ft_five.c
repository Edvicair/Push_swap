/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:26:53 by edvicair          #+#    #+#             */
/*   Updated: 2021/11/30 09:36:06 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	ft_t_nbr(t_stack *st)
{
	t_nbr	a;
	t_list	*tmp;

	tmp = st->a;
	a.nb1 = tmp->nb;
	tmp = tmp->next;
	a.nb2 = tmp->nb;
	tmp = tmp->next;
	a.nb3 = tmp->nb;
	if (tmp->next)
	{
		tmp = tmp->next;
		a.nb4 = tmp->nb;
	}
	if (tmp->next)
	{
		tmp = tmp->next;
		a.nb5 = tmp->nb;
	}
	tmp = tmp->next;
	return (a);
}

void	ft_sort(t_stack **st, int nb)
{
	if (nb == 1)
	{
		*st = ft_write_algo1("pa\n", *st);
		*st = ft_write_algo("sa\n", *st);
	}
	if (nb == 2)
	{
		*st = ft_write_algo1("pa\n", *st);
		*st = ft_write_algo("ra\n", *st);
	}
	if (nb == 3)
	{	
		*st = ft_write_algo1("rra\n", *st);
		*st = ft_write_algo1("pa\n", *st);
		*st = ft_write_algo("ra\n", *st);
		*st = ft_write_algo("ra\n", *st);
	}
	if (nb == 4)
	{	
		*st = ft_write_algo("ra\n", *st);
		*st = ft_write_algo("ra\n", *st);
		*st = ft_write_algo1("pa\n", *st);
		*st = ft_write_algo1("rra\n", *st);
		*st = ft_write_algo1("rra\n", *st);
	}
}

void	ft_sort_tree(t_stack *st)
{
	int		b;
	t_nbr	a;

	b = st->b->nb;
	a = ft_t_nbr(st);
	if (b < a.nb1 && b < a.nb2 && b < a.nb3)
		st = ft_write_algo1("pa\n", st);
	if (b > a.nb1 && b < a.nb2 && b < a.nb3)
		ft_sort(&st, 1);
	if (b > a.nb1 && b > a.nb2 && b > a.nb3)
		ft_sort(&st, 2);
	if (b > a.nb1 && b > a.nb2 && b < a.nb3)
		ft_sort(&st, 3);
}

void	ft_sort_four(t_stack *st)
{
	int		b;
	t_nbr	a;

	b = st->b->nb;
	a = ft_t_nbr(st);
	if (b < a.nb1 && b < a.nb2 && b < a.nb3 && b < a.nb4)
		st = ft_write_algo1("pa\n", st);
	if (b > a.nb1 && b < a.nb2 && b < a.nb3 && b < a.nb4)
		ft_sort(&st, 1);
	if (b > a.nb1 && b > a.nb2 && b > a.nb3 && b > a.nb4)
		ft_sort(&st, 2);
	if (b > a.nb1 && b > a.nb2 && b > a.nb3 && b < a.nb4)
		ft_sort(&st, 3);
	if (b > a.nb1 && b > a.nb2 && b < a.nb3 && b < a.nb4)
		ft_sort(&st, 4);
}

void	ft_before_five(t_stack *st, int four)
{
	t_nbr	a;

	a = ft_t_nbr(st);
	if (a.nb1 < a.nb2 && a.nb1 > a.nb3 && a.nb1 < a.nb4 && a.nb1 > a.nb5
		&& a.nb2 > a.nb3 && a.nb2 < a.nb4 && a.nb2 > a.nb5
		&& a.nb3 < a.nb4 && a.nb3 < a.nb5 && a.nb4 > a.nb5)
	{	
		st = ft_write_algo1("rra\n", st);
		st = ft_write_algo1("rra\n", st);
		st = ft_write_algo1("rra\n", st);
		st = ft_write_algo("sa\n", st);
		st = ft_write_algo("ra\n", st);
		return ;
	}
	if (a.nb1 < a.nb2 && a.nb1 < a.nb3 && a.nb1 > a.nb4 && a.nb1 > a.nb5
		&& a.nb2 < a.nb3 && a.nb2 > a.nb4 && a.nb2 > a.nb5
		&& a.nb3 > a.nb4 && a.nb3 > a.nb4 && a.nb4 > a.nb5)
	{
		st = ft_write_algo1("rra\n", st);
		st = ft_write_algo1("rra\n", st);
		st = ft_write_algo("sa\n", st);
		return ;
	}
	ft_five(st, four);
}
