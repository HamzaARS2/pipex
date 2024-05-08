/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:52:40 by helarras          #+#    #+#             */
/*   Updated: 2024/05/07 04:10:37 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freeall(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

char	*get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (env[i] + 5);
		i++;
	}
	return (0);
}

char	**split_path(char **env)
{
	size_t	i;
	char	*temp;
	char	**paths;

	i = 0;
	paths = ft_split(get_env_path(env), ':');
	if (!paths)
		return (0);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
		{
			freeall(paths, i - 1);
			return (0);
		}
		free(paths[i]);
		paths[i] = temp;
		i++;
	}
	return (paths);
}
