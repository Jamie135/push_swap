/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:05:18 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 11:01:48 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

# define BUFFEER_SIZE 5

/* utils.c */
int			split_argv(char ***array, char **argv, char *split);
int			is_sorted(t_list *stack);

/* is_valid.c */
int			is_valid(char **array);

/* instructions.c */
int			ft_abs(int i);
void		run(char *cmd, t_list **stack_a, t_list **stack_b, int x);

/* sort_big_utils */
int			stack_id_minmax(t_list *stack, int n);
void		get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void		rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void		rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);

/* sort_utils.c */
int			stack_min(t_list *stack);
int			stack_max(t_list *stack);
int			min(int a, int b);

/* sort.c */
void		sort(t_list **stack);

/* get_next_line.c */
char		*get_next_line(char **str);

#endif
