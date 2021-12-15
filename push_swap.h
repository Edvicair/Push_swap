/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:47:15 by edvicair          #+#    #+#             */
/*   Updated: 2021/12/15 00:31:54 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int		nb;
	struct s_list	*next;
}			t_list;

typedef struct s_stack
{
	struct s_list	*a;
	struct s_list	*b;
	struct s_list	*str;
}			t_stack;

typedef struct s_nbr
{
	int	nb1;
	int	nb2;
	int	nb3;
	int	nb4;
	int	nb5;
}		t_nbr;

typedef struct s_nb
{
	int	start;
	int	start_pos;
	int	end;
	int	end_pos;
}		t_nb;

int		ft_order(t_list *a);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_check(int ac, char **av);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
int		*tab_cpy(int *src, int size);
int		*ft_init_tab(t_list *a, int size);
int		*ft_sort_tab(int *tab, int size);
int		ft_max(t_list *a);
char	*ft_itoa(int n, unsigned int j);
t_stack	*ft_write_algo(char *str, t_stack *st);
t_stack	*ft_write_algo1(char *str, t_stack *st);
t_stack	*ft_quick_five(t_stack *st);
t_stack	*big_rotate_a(t_stack *st, t_nb nb);
t_stack	*ft_remoov(t_stack *st);
t_list	*ft_init(int ac, char **av);
t_list	*ft_swap_stack(t_list *stack);
t_list	*ft_rotate(t_list *stack);
t_list	*ft_r_rotate(t_list *stack);
t_nb	ft_tab_end(int *tab, int *tab_sort, int size, int slice);
void	ft_error(void);
void	ft_push_stack(t_list **a, t_list **b);
void	ft_sort_tree(t_stack *st);
void	ft_sort_four(t_stack *st);
void	ft_before_five(t_stack *st, int four);
void	ft_five(t_stack *st, int four);

#endif
