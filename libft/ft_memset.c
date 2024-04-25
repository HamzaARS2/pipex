/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:43:51 by helarras          #+#    #+#             */
/*   Updated: 2024/01/01 11:16:15 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*v;
	size_t			i;

	v = (unsigned char *)b;
	i = 0;
	while (i < length)
	{
		v[i] = (unsigned char)c;
		i++;
	}
	return (v);
}
