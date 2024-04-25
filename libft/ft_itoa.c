/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:00:53 by helarras          #+#    #+#             */
/*   Updated: 2023/12/29 19:50:19 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	charcat(char *dst, long number, size_t i)
{
	if (number < 0)
	{
		dst[0] = '-';
		number *= -1;
	}
	if (number < 10)
		dst[i - 1] = number + 48;
	else
	{
		charcat(dst, number / 10, i - 1);
		charcat(dst, number % 10, i);
	}
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	digits;

	digits = intlen(n);
	if (n < 0)
		digits++;
	dst = malloc((digits + 1) * sizeof(char));
	if (!dst)
		return (0);
	charcat(dst, n, digits);
	dst[digits] = 0;
	return (dst);
}
