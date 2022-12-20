/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:25:43 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/20 13:25:43 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->num = 0;
	first->diff = 1;
	first->next = NULL;
	return (first);
}

t_stack	*init_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = new_node();
	tmp = first;
	while (i < argc)
	{
		if (check_arg(argv[i]))
		{
			/* code */
		}
		
	}
	
}