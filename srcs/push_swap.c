/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:19:26 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 13:35:28 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**array;
	t_list	*stack;

	if (argc > 1)
	{
		array = 0;
		len = split_list(&array, argv + 1, " ");
		if (!len || !valid_arg(array))
		{
			free_array(array);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(array[len]));
		if (!valid_sort(stack))
			sort(&stack);
		ft_lstclear(&stack, free);
		free(array);
	}
	return (0);
}
