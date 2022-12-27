/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:03:14 by pbureera          #+#    #+#             */
/*   Updated: 2022/12/27 23:03:14 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		n = n * 10 + sign * (*str++ - '0');
		if (sign < 0 && n > 0)
			return (LONG_MIN);
		else if (sign > 0 && n < 0)
			return (LONG_MAX);
	}
	return (n);
}

static int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	if (ft_atol(str) < -2147483648 || ft_atol(str) > 2147483647)
		return (0);
	return (1);
}

static int	is_duplicate(int *num, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_valid(char **array)
{
	int	i;
	int	result;
	int	*num;
	int	tmp;

	i = 0;
	result = 0;
	while (array[i])
	{
		if (!is_int(array[i++]))
			return (result);
	}
	num = malloc(sizeof(int) * i);
	if (!num)
		return (result);
	tmp = i;
	while (i--)
		num[i] = ft_atoi(array[i]);
	if (!is_duplicate(num, tmp))
		result = 1;
	free(num);
	return (result);
}
