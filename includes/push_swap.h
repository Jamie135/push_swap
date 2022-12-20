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
# include "libft.h"

typedef struct s_stack
{
	int				num;
	int				diff;
	struct s_stack	*next;
}					t_stack;

typedef struct s_comp
{
	int			rotator;
	char		*final;
}				t_comp;

/* check_error.c */


/* init_stack.c */
t_stack	*new_node(void);
t_stack	*init_stack(int argc, char **argv);

/* push_swap.c */

#endif
