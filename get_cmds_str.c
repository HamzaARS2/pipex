/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:00:59 by helarras          #+#    #+#             */
/*   Updated: 2024/05/04 16:02:42 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freeall(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

char	**get_cmds_str(char **data, size_t size)
{
	char	**cmds_str;
	int		i;
	int		end;

	if (size < 3)
		return (0);
	cmds_str = malloc((size - 1) * sizeof(char *));
	if (!cmds_str)
		return (0);
	i = 0;
	end = size - 1;
	while (++i < end)
	{
		cmds_str[i - 1] = ft_strdup(data[i]);
		if (!cmds_str[i - 1])
		{
			freeall(cmds_str, i - 2);
			return (0);
		}
	}
	cmds_str[i - 1] = 0;
	return (cmds_str);
}
