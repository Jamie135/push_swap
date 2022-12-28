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
int			ft_abs(int i);
void		run(char *cmd, t_list **stack_a, t_list **stack_b, int x);

/* sort_big_utils */
int			stack_id_minmax(t_list *stack, int n);
static int	stack_id_mid(t_list *stack, int n);
void		get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void		rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);

/* sort_utils.c */
int			stack_min(t_list *stack);
int			stack_max(t_list *stack);
int			min(int a, int b);

/* sort.c */


#endif
