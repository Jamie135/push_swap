/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:49:26 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/28 00:49:26 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static void	sx(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	(void)stack_b;
	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		ft_lstadd_front(stack_a, tmp);
	}
}

static void	px(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, tmp);
	}
}

static void	rx(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	(void)stack_b;
	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = 0;
		ft_lstadd_back(stack_a, tmp);
	}
}

static void	rrx(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	(void)stack_b;
	if (ft_lstsize(*stack_a) >= 2)
	{
		last = *stack_a;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack_a;
		*stack_a = last;
	}
}

void	run(char *cmd, t_list **stack_a, t_list **stack_b, int x)
{
	int			tmp;
	void		(*f)(t_list **, t_list **);
	const int	len = ft_strlen(cmd);

	tmp = ft_abs(x);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &sx;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &px;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &rx;
	else
		f = &rrx;
	while (tmp--)
	{
		f(stack_a, stack_b);
		if (stack_b && f != px)
			f(stack_b, 0);
		if (x > 0)
			ft_putendl_fd(cmd, 1);
	}
}
