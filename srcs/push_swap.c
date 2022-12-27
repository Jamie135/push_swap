/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:19:26 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/20 13:19:26 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	char	**array;
	t_list	*stack;

	if (argc > 1)
	{
		array = 0;
		len = split_argv(&array, argv + 1, " ");
		if (!len || !is_valid(array))
		{
			ps_free(array);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(array[len]));
		if (!is_sorted(stack))
			sort(&stack);
	}
}

