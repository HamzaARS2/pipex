/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:38:09 by helarras          #+#    #+#             */
/*   Updated: 2023/12/17 13:25:24 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dst;
	csrc = (char *)src;
	if (cdest > csrc)
	{
		while (len-- > 0)
			cdest[len] = csrc[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
