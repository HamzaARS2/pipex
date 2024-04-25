/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:33:06 by helarras          #+#    #+#             */
/*   Updated: 2024/01/01 22:15:07 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s1_bytes;
	char	*dest;

	i = 0;
	s1_bytes = ft_strlen(s1) + 1;
	dest = (char *)malloc(s1_bytes * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, s1_bytes);
	return (dest);
}
