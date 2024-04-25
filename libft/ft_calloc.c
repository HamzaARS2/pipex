/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:57:17 by helarras          #+#    #+#             */
/*   Updated: 2023/12/29 22:14:23 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	bytes;
	char	*ptr;

	i = 0;
	bytes = count * size;
	if (size && count != bytes / size)
		return (0);
	ptr = (char *)malloc(bytes);
	if (!ptr)
		return (0);
	ft_bzero(ptr, bytes);
	return ((void *)ptr);
}
