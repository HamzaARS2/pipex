/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeul_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:09:28 by helarras          #+#    #+#             */
/*   Updated: 2024/01/09 21:41:20 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	writeul_base(unsigned long number, char *base, unsigned int nbase)
{
	size_t	ccount;

	ccount = 0;
	if (number >= nbase)
		ccount += writeul_base(number / nbase, base, nbase);
	return (write(1, base + (number % nbase), 1) + ccount);
}
