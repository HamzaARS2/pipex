/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:50 by helarras          #+#    #+#             */
/*   Updated: 2023/12/27 16:26:39 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	newstrlen;
	size_t	s1len;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	newstrlen = s1len + ft_strlen(s2);
	newstr = malloc((newstrlen + 1) * sizeof(char));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1, s1len + 1);
	ft_strlcat(newstr, s2, newstrlen + 1);
	return (newstr);
}
