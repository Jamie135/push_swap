/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:05:18 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 13:47:48 by pbureera         ###   ########.fr       */
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
int			split_list(char ***array, char **argv, char *split);
int			valid_arg(char **array);
int			valid_sort(t_list *stack);

/* instructions.c */
void		instruct(char *cmd, t_list **stack_a, t_list **stack_b, int x);

/* sort.c */
void		sort(t_list **stack);

/* sort_utils.c */
int			stack_min(t_list *stack);
int			stack_max(t_list *stack);
int			min(int a, int b);

/* sort_big_utils */
int			stack_minmax(t_list *stack, int n);
void		rotate_min(t_list *stack_a, t_list *stack_b, int *a, int *b);
void		rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void		rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);

/* get_next_line.c */
char		*get_next_line(char **str);

#endif
