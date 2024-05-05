/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:26:17 by helarras          #+#    #+#             */
/*   Updated: 2024/01/09 21:08:03 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	writeaddress(unsigned long n)
{
	size_t	ccount;

	ccount = 0;
	ccount += write(1, "0x", 2);
	ccount += writeul_base(n, "0123456789abcdef", 16);
	return (ccount);
}

static size_t	writearg(char fmtspec, va_list ap)
{
	size_t	ccount;

	ccount = 0;
	if (fmtspec == 'c')
		ccount += writechar(va_arg(ap, int));
	else if (fmtspec == 's')
		ccount += writestr(va_arg(ap, char *));
	if (fmtspec == 'i' || fmtspec == 'd')
		ccount += writei_base(va_arg(ap, int), "0123456789", 10);
	else if (fmtspec == 'u')
		ccount += writeul_base(va_arg(ap, unsigned int), "0123456789", 10);
	else if (fmtspec == 'x')
		ccount += writeul_base(va_arg(ap, unsigned int), "0123456789abcdef",
				16);
	else if (fmtspec == 'X')
		ccount += writeul_base(va_arg(ap, unsigned int), "0123456789ABCDEF",
				16);
	else if (fmtspec == 'p')
		ccount += writeaddress(va_arg(ap, unsigned long));
	else if (fmtspec == '%')
		ccount += write(1, "%", 1);
	return (ccount);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	ccount;

	i = 0;
	ccount = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 0)
				return (ccount);
			ccount += writearg(str[++i], ap);
		}
		else
			ccount += write(1, str + i, 1);
		i++;
	}
	va_end(ap);
	return (ccount);
}
