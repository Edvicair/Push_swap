/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:03:52 by edvicair          #+#    #+#             */
/*   Updated: 2021/12/15 00:24:23 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_stack *st)
{
	int		a;
	int		b;
	int		c;
	t_list	*tmp1;

	tmp1 = st->a;
	a = tmp1->nb;
	tmp1 = tmp1->next;
	b = tmp1->nb;
	tmp1 = tmp1->next;
	c = tmp1->nb;
	if ((a > b && b < c && c > a) || (a > b && b > c
			&& c < a) || (a < b && b > c && c > a))
		st = ft_write_algo("sa\n", st);
	if (a < b && b > c && c < a)
		st = ft_write_algo1("rra\n", st);
	if (a > b && b < c && c < a)
		st = ft_write_algo("ra\n", st);
}

void	ft_five(t_stack *st, int four)
{
	if (four == 0)
		st = ft_write_algo1("pb\n", st);
	st = ft_write_algo1("pb\n", st);
	ft_three(st);
	if (ft_order(st->a) == 1)
		ft_three(st);
	ft_sort_tree(st);
	if (four == 0)
		ft_sort_four(st);
}

t_stack	*ft_choose(t_stack *st, int ac)
{
	int	four;

	four = 0;
	if (ac == 3)
		st = ft_write_algo("sa\n", st);
	else if (ac == 4)
	{
		ft_three(st);
		if (ft_order(st->a) == 1)
			ft_three(st);
	}
	else if (ac == 5 || ac == 6)
	{
		if (ac == 5)
			four = 1;
		ft_before_five(st, four);
	}
	else
		ft_quick_five(st);
	return (st);
}

int	main(int ac, char **av)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (0);
	st->a = NULL;
	st->b = NULL;
	if (ac == 1)
	{
		free(st);
		return (0);
	}
	if ((ac <= 2) || ft_check(ac, av) == -1)
	{
		free(st);
		if (ft_check(ac, av) == -1)
			ft_error();
		return (0);
	}
	st->a = ft_init(ac, av);
	st->b = ft_init(0, NULL);
	if (ft_order(st->a) == 1)
		st = ft_choose(st, ac);
	return (0);
}
