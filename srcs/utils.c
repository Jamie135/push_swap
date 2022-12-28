/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:16:48 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/27 19:16:48 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	split_argv(char ***array, char **argv, char *split)
{
	char	*str;
	char	*tmp;
	int		i;

	str = 0;
	while (*argv)
	{
		if (!str)
			str = ft_strdup(*argv++);
		else
		{
			tmp = str;
			str = ft_strjoin(str, split);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, *argv++);
			free(tmp);
		}
	}
	*array = ft_split(str, *split);
	free(str);
	i = 0;
	while ((*array)[i])
		i++;
	return (i); 
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
