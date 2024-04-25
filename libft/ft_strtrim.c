/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:36:17 by helarras          #+#    #+#             */
/*   Updated: 2023/12/29 19:52:30 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char const *str, char const c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = 0;
	while (s1[start] && is_exist(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (end > start && is_exist(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
