/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:18:12 by edvicair          #+#    #+#             */
/*   Updated: 2021/11/30 11:39:28 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap_stack(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack;
	tmp2 = stack->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	return (tmp2);
}

t_list	*ft_rotate(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack;
	tmp2 = stack->next;
	while (stack->next)
		stack = stack->next;
	tmp1->next = NULL;
	stack->next = tmp1;
	return (tmp2);
}

t_list	*ft_r_rotate(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	tmp1 = stack;
	while (stack->next)
	{
		tmp2 = stack;
		stack = stack->next;
	}
	tmp2->next = NULL;
	stack->next = tmp1;
	return (stack);
}

void	ft_push_stack(t_list **a, t_list **b)
{
	t_list	*tmp1;

	if (*a != NULL)
	{
		tmp1 = *a;
		*a = (*a)->next;
		if (*b == NULL)
			tmp1->next = NULL;
		else
			tmp1->next = *b;
		*b = tmp1;
	}
}
