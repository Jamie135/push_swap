/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 00:10:20 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/29 00:10:20 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_id_minmax(t_list *stack, int n)
{
	int			num;
	int			x;
	const int	size = ft_lstsize(stack);

	num = 0;
	x = stack_max(stack);
	if (n <= stack_min(stack))
		x = stack_min(stack);
	else
		++num;
	while (stack)
	{
		if (ft_atoi(stack->content) == x)
			break;
		++num;
		stack = stack->next;
	}
	if (num >= (size + 1) / 2)
		num = -1 * (size - num);
	return (num);
}

static int	stack_id_mid(t_list *stack, int n)
{
	int			current;
	int			next;
	int			num;
	const int	size = ft_lstsize(stack);

	num = -1;
	while (stack->next)
	{
		current = ft_atoi(stack->content);
		next = ft_atoi(stack->next->content);
		if (n > current && n < next)
			break;
		++num;
		stack = stack->next;
	}
	if (num == size)
		num = 0;
	else if (num >= (size + 1) / 2)
		num = -1 * (size - num);
	return (num);
}

void	get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	int			i;
	int			j;
	int			n;
	int			x;
	const int	size_b = ft_lstsize(stack_b);

	x = -1;
	while (stack_b && ++x >= 0)
	{
		n = ft_atoi(stack_b->content);
		if (n < stack_min(stack_a) || n > stack_max(stack_a))
			i = stack_id_minmax(stack_a, n);
		else
			i = stack_id_mid(stack_a, n);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->next;
	}
}

void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		run("rr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			run("rb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			run("ra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		run("rrr", stack_a, stack_b, min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			run("rrb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			run("rra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		run("ra", stack_a, 0, a);
		run("rrb", stack_b, 0, ft_abs(min(a, b)));
	}
	else
	{
		run("rb", stack_b, 0, b);
		run("rra", stack_a, 0, ft_abs(min(a, b)));
	}
}