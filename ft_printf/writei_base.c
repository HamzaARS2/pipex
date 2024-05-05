/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writei_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:07 by helarras          #+#    #+#             */
/*   Updated: 2024/01/09 16:29:36 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	writei_base(int number, char *base, unsigned int nbase)
{
	long	nbr;
	size_t	ccount;

	nbr = number;
	ccount = 0;
	if (nbr < 0)
	{
		ccount += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= nbase)
		ccount += writeul_base(nbr / nbase, base, nbase);
	return (write(1, base + (nbr % nbase), 1) + ccount);
}
