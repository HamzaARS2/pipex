/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:51:16 by helarras          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:12 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strsize;
	size_t	sublen;

	if (!str)
		return (0);
	strsize = ft_strlen(str);
	if (start > strsize)
	{
		sublen = 0;
		start = strsize;
	}
	else
	{
		if (strsize - start > len)
			sublen = len;
		else
			sublen = strsize - start;
	}
	substr = malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, str + start, sublen + 1);
	return (substr);
}
