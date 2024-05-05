/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:12:40 by helarras          #+#    #+#             */
/*   Updated: 2024/01/20 13:40:08 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(char **s, char **line)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i++] == '\n')
			break ;
	}
	*line = malloc(i + 1);
	if (!(*line))
		return (sclear(s));
	while ((*s)[k++] && k <= i)
		(*line)[k - 1] = (*s)[k - 1];
	(*line)[k - 1] = 0;
	return ((*s) + i);
}

char	*readnext(int fd, char **s)
{
	char	*buffer;
	int		charsread;
	int		isfound;

	isfound = 0;
	while (!isfound)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (sclear(s));
		charsread = read(fd, buffer, BUFFER_SIZE);
		buffer[charsread] = 0;
		if (charsread <= 0)
		{
			free(buffer);
			if (charsread == 0)
				return (*s);
			return (sclear(s));
		}
		isfound = is_exists(buffer, '\n');
		*s = strcombine(*s, buffer);
		if (!(*s))
			return (*s);
	}
	return (*s);
}

char	*update_s(char **s, char *remaining)
{
	char	*new_s;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (remaining[k])
		k++;
	if (k > 0)
	{
		new_s = malloc(k + 1);
		if (!new_s)
			return (sclear(s));
		while (remaining[i++])
			new_s[i - 1] = remaining[i - 1];
		new_s[i - 1] = 0;
	}
	else
		new_s = 0;
	sclear(s);
	*s = new_s;
	return (*s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (sclear(&s));
	if (!readnext(fd, &s))
		return (0);
	remaining = readline(&s, &line);
	if (!remaining)
		return (0);
	update_s(&s, remaining);
	return (line);
}
