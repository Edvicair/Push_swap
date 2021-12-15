/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:43:19 by edvicair          #+#    #+#             */
/*   Updated: 2021/11/30 11:35:56 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_write_algo(char *str, t_stack *st)
{
	if (str [0] == 's' && str[1] == 'a')
		st->a = ft_swap_stack(st->a);
	else if (str [0] == 's' && str[1] == 'b')
		st->b = ft_swap_stack(st->a);
	else if (str [0] == 's' && str[1] == 's')
	{
		st->a = ft_swap_stack(st->a);
		st->b = ft_swap_stack(st->a);
	}
	else if (str[0] == 'r' && str[1] == 'a')
		st->a = ft_rotate(st->a);
	else if (str[0] == 'r' && str[1] == 'b')
		st->b = ft_rotate(st->b);
	else if (str[0] == 'r' && str[1] == 'r')
	{
		st->a = ft_rotate(st->a);
		st->b = ft_rotate(st->b);
	}
	write(1, str, 3);
	return (st);
}

t_stack	*ft_write_algo1(char *str, t_stack *st)
{
	if (str[0] == 'r' && (str[2] == 'a' || str[2] == 'b' || str[2] == 'r'))
	{
		if (str[2] == 'a')
			st->a = ft_r_rotate(st->a);
		else if (str[2] == 'b')
			st->b = ft_r_rotate(st->b);
		else
		{
			st->a = ft_r_rotate(st->a);
			st->b = ft_r_rotate(st->b);
		}
		write(1, str, 4);
	}
	else if (str[0] == 'p' && (str[1] == 'a' || str[1] == 'b'))
	{
		if (str[1] == 'a')
			ft_push_stack(&st->b, &st->a);
		else
			ft_push_stack(&st->a, &st->b);
		write(1, str, 3);
	}
	return (st);
}
