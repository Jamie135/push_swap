/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:45:17 by pbureera          #+#    #+#             */
/*   Updated: 2023/01/19 13:29:19 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	gnl_read(char *buff, char **str)
{
	int		i;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(0, buff, BUFFEER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!*str)
				*str = ft_strdup(buff);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buff);
				free(tmp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(0, buff, BUFFEER_SIZE);
		}
	}
	free(buff);
}

static char	*gnl_process(char **str)
{
	int		i;
	int		j;
	char	*s;
	char	*tmp;

	if (!*str)
		return (0);
	if (!ft_strchr(*str, '\n'))
	{
		s = ft_strdup(*str);
		free(*str);
		*str = 0;
		return (s);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	s = ft_substr(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(tmp);
	return (s);
}

char	*get_next_line(char **str)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFEER_SIZE + 1));
	if (!buff)
		return (0);
	gnl_read(buff, str);
	return (gnl_process(str));
}
