/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:04:32 by helarras          #+#    #+#             */
/*   Updated: 2023/12/29 22:04:42 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	powerof(long nbr)
{
	size_t	power;

	power = 1;
	nbr /= 10;
	while (nbr)
	{
		nbr /= 10;
		power *= 10;
	}
	return (power);
}

static void	writenumber(long number, int fd, size_t power)
{
	long	n;

	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	while (power)
	{
		n = (number / power) + 48;
		write(fd, &n, 1);
		number %= power;
		power /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	power;

	power = powerof(n);
	writenumber(n, fd, power);
}
