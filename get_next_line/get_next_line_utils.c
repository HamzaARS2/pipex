/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:12:56 by helarras          #+#    #+#             */
/*   Updated: 2024/05/05 11:58:06 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	is_exists(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*sclear(char **s)
{
	free(*s);
	*s = 0;
	return (*s);
}

char	*strcombine(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	newstrlen;
	char	*newstr;

	if (!s1 && !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	newstrlen = s1_len + ft_strlen(s2);
	newstr = malloc(newstrlen + 1);
	if (newstr)
	{
		while (s1 && s1[i++])
			newstr[i - 1] = s1[i - 1];
		i = 0;
		while (s2 && s2[i++])
			newstr[s1_len + (i - 1)] = s2[i - 1];
		newstr[newstrlen] = 0;
	}
	sclear(&s1);
	sclear(&s2);
	return (newstr);
}
