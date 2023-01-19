/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:52:13 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 10:54:59 by pbureera         ###   ########.fr       */
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

static int	message_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse(char *str, t_list **stack_1, t_list **stack_2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ps_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		run(str, stack_1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		run(str, stack_2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		run(str, stack_1, stack_2, -1);
	else if (!f(str, "pa", 2))
		run(str, stack_2, stack_1, -1);
	else
		return (ps_error());
	return (0);
}

static void	sort_check(t_list **stack_a)
{
	char		*cmd;
	t_list		*stack_b;
	static char	*str;

	stack_b = 0;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (parse(cmd, stack_a, &stack_b))
		{
			free(str);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(*stack_a) && !ft_lstsize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

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
		sort_check(&stack);
		ft_lstclear(&stack, free);
		free(array);
	}
	return (0);
}
