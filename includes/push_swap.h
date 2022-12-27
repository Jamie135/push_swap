/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:05:18 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/20 12:05:18 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

# define BUFFEER_SIZE 5

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* utils.c */
int			split_argv(char ***array, char **argv, char *split);
int			is_sorted(t_list *stack);

/* is_valid.c */
static int	is_int(char *str);

/* instructions.c */
void		run(char *cmd, t_list **stack_a, t_list **stack_b, int x);

/* sort.c */


#endif
