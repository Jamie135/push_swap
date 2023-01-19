/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:42:40 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 13:49:10 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	sort_three(t_list **stack)
{
	const int	num_1 = ft_atoi((*stack)->content);
	const int	num_2 = ft_atoi((*stack)->next->content);
	const int	num_3 = ft_atoi((*stack)->next->next->content);

	if (num_1 == stack_min(*stack) && num_2 == stack_max(*stack))
	{
		instruct("sa", stack, 0, 1);
		instruct("ra", stack, 0, 1);
	}
	else if (num_2 == stack_min(*stack) && num_3 == stack_max(*stack))
		instruct("sa", stack, 0, 1);
	else if (num_3 == stack_min(*stack) && num_2 == stack_max(*stack))
		instruct("rra", stack, 0, 1);
	else if (num_2 == stack_min(*stack) && num_1 == stack_max(*stack))
		instruct("ra", stack, 0, 1);
	else
	{
		instruct("sa", stack, 0, 1);
		instruct("rra", stack, 0, 1);
	}
}

static void	sort_large(t_list **stack_a)
{
	int		a;
	int		b;
	t_list	*stack_b;

	stack_b = 0;
	while (ft_lstsize(*stack_a) > 3)
		instruct("pb", stack_a, &stack_b, 1);
	if (!valid_sort(*stack_a))
		sort_three(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0;
		b = 0;
		rotate_min(*stack_a, stack_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			rotate_same(stack_a, &stack_b, a, b);
		else
			rotate_diff(stack_a, &stack_b, a, b);
		instruct("pa", &stack_b, stack_a, 1);
	}
}

static void	sort_last(t_list **stack)
{
	const int	i = stack_minmax(*stack, stack_min(*stack));

	if (i < 0)
		instruct("rra", stack, 0, -i);
	else
		instruct("ra", stack, 0, i);
}

void	sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		instruct("sa", stack, 0, 1);
	else if (ft_lstsize(*stack) == 3)
		sort_three(stack);
	else
		sort_large(stack);
	sort_last(stack);
}
