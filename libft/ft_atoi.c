/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:03:32 by helarras          #+#    #+#             */
/*   Updated: 2024/01/01 10:52:50 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipspaces(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	number;
	long	temp;

	number = 0;
	sign = 1;
	i = skipspaces(str);
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		temp = number;
		number = (number * 10) + str[i++] - 48;
		if (number / 10 != temp && sign > 0)
			return (-1);
		if (number / 10 != temp && sign < 0)
			return (0);
	}
	return (number * sign);
}
