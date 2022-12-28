/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:42:52 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/28 23:42:52 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_min(t_list *stack)
{
	int	min;
	int	n;

	min = ft_atoi(stack->content);
	while (stack)
	{
		n = ft_atoi(stack->content);
		if (min > n)
			min = n;
		stack =	stack->next;
	}
	return (min);
}

int	stack_max(t_list *stack)
{
	int	max;
	int	n;

	max = ft_atoi(stack->content);
	while (stack)
	{
		n = ft_atoi(stack->content);
		if (max < n)
			max = n;
		stack = stack->next;
	}
	return (max);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
