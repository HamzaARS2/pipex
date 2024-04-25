/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:15:02 by helarras          #+#    #+#             */
/*   Updated: 2023/12/28 21:47:00 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	tofind;

	i = 0;
	str = (unsigned char *)s;
	tofind = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == tofind)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
