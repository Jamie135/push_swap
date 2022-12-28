/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:42:40 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/28 00:42:40 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_list **stack)
{
	const int	n1 = ft_atoi((*stack)->content);
	const int	n2 = ft_atoi((*stack)->next->content);
	const int	n3 = ft_atoi((*stack)->next->next->content);

	if (n1 == stack_min(*stack) && n2 == stack_max(*stack))
	{
		run("sa", stack, 0, 1);
		run("ra", stack, 0, 1);
	}
	else if (n2 == stack_min(*stack) && n3 == stack_max(*stack))
		run("sa", stack, 0, 1);
	else if (n3 == stack_min(*stack) && n2 == stack_max(*stack))
		run("rra", stack, 0, 1);
	else if (n2 == stack_min(*stack) && n1 == stack_max(*stack))
		run("ra", stack, 0, 1);
	else
	{
		run("sa", stack, 0, 1);
		run("rra", stack, 0, 1);
	}
}

static void	sort_big(t_list **stack_a)
{
	int		a;
	int		b;
	t_list	*stack_b;

	stack_b = 0;
	while (ft_lstsize(*stack_a) > 3)
		run("pb", stack_a, &stack_b, 1);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0;
		b = 0;
		get_min_rotate(*stack_a, stack_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		run("pa", &stack_b, stack_a, 1);
	}
}

static void	sort_final(t_list **stack)
{
	const int	i = stack_id_minmax(*stack, stack_min(*stack));

	if (i < 0)
		run("rra", stack, 0, -i);
	else
		run("ra", stack, 0, i);
}

void	sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		run("sa", stack,0 , 1);
	else if (ft_lstsize(*stack) == 3)
		sort_three(stack);
	else
		sort_big(stack);
	sort_final(stack);
}
