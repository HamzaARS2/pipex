/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:00:26 by helarras          #+#    #+#             */
/*   Updated: 2023/12/31 15:22:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char delimeter)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delimeter)
			i++;
		while (str[i] && str[i] != delimeter)
			i++;
		if (i > 0 && str[i - 1] != delimeter)
			count++;
	}
	return (count);
}

static void	freewords(char **words, int i)
{
	while (i >= 0 && words[i])
		free(words[i--]);
	free(words);
}

static char	**strcut(char **words, char const *str, char delimeter,
		size_t wcount)
{
	size_t	i;
	size_t	ccount;
	size_t	windex;

	i = 0;
	ccount = 0;
	windex = 0;
	while (str[i] && windex < wcount)
	{
		while (str[i] == delimeter)
			i++;
		while (str[i + ccount] && str[i + ccount] != delimeter)
			ccount++;
		words[windex] = ft_substr(str, i, ccount);
		if (!words[windex])
		{
			freewords(words, windex - 1);
			return (0);
		}
		i += ccount;
		ccount = 0;
		windex++;
	}
	words[windex] = 0;
	return (words);
}

char	**ft_split(char const *str, char c)
{
	size_t	wcount;
	char	**words;

	if (!str)
		return (0);
	wcount = count_words(str, c);
	words = malloc((wcount + 1) * sizeof(char *));
	if (!words || !strcut(words, str, c, wcount))
		return (0);
	return (words);
}
