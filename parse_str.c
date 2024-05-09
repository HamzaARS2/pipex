/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:28:18 by helarras          #+#    #+#             */
/*   Updated: 2024/05/09 12:18:49 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	skip_delimeter(char const *str, size_t *i, char *delimeter)
{
	while (str[*i] == *delimeter)
		(*i)++;
	if (str[*i] == 34 || str[*i] == 39)
	{
		*delimeter = str[*i];
		(*i)++;
	}
}

static int	count_words(char const *str, char delimeter)
{
	size_t	i;
	size_t	size;
	size_t	count;

	i = 0;
	count = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		skip_delimeter(str, &i, &delimeter);
		while (str[i] && str[i] != delimeter)
			i++;
		if (i > 0 && str[i - 1] != delimeter)
			count++;
		i++;
		delimeter = 32;
	}
	return (count);
}

static int	freewords(char **words, int i)
{
	while (i >= 0 && words[i])
		free(words[i--]);
	free(words);
	return (0);
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
		skip_delimeter(str, &i, &delimeter);
		while (str[i + ccount] && str[i + ccount] != delimeter)
			ccount++;
		words[windex] = ft_substr(str, i, ccount);
		if (!words[windex])
		{
			freewords(words, windex - 1);
			return (0);
		}
		i += ccount + 1;
		ccount = 0;
		windex++;
		delimeter = 32;
	}
	words[windex] = 0;
	return (words);
}

char	**parse_str(char *str)
{
	size_t	wcount;
	char	**words;
	char	delimiter;

	delimiter = 32;
	if (!str)
		return (0);
	wcount = count_words(str, delimiter);
	if (!wcount)
	{
		delimiter = 0;
		wcount = count_words(str, delimiter);
	}
	words = malloc((wcount + 1) * sizeof(char *));
	if (!words || !strcut(words, str, delimiter, wcount))
		return (0);
	return (words);
}
