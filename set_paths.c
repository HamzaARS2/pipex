/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:12:44 by helarras          #+#    #+#             */
/*   Updated: 2024/05/09 17:12:49 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*assign_path(char *cmd, char *path)
{
	char	*pcmd;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	pcmd = ft_strjoin(path, cmd);
	return (pcmd);
}

int	check_access(char *pcmd)
{
	int	status;

	status = 0;
	if (access(pcmd, F_OK) == -1)
		status = 'F';
	if (!status && access(pcmd, X_OK) == -1)
		status = 'X';
	return (status);
}

int	set_cmd_path(char **cmd, char **paths)
{
	size_t	i;
	char	*pcmd;
	int		status;

	i = 0;
	status = 'F';
	while (paths[i] && status)
	{
		pcmd = assign_path(*cmd, paths[i++]);
		status = check_access(pcmd);
		if (status)
			free(pcmd);
		if (pcmd == *cmd)
			return (handle_error(status, pcmd));
	}
	if (!status)
	{
		free(*cmd);
		*cmd = pcmd;
	}
	return (handle_error(status, *cmd));
}

void	set_paths(t_cmds *cmds, char **paths)
{
	size_t	i;
	int		status;
	int		error;

	i = 0;
	error = 0;
	while (cmds->list[i])
	{
		status = set_cmd_path(cmds->list[i], paths);
		if (status)
			error = status;
		i++;
	}
	if (error)
		exit(EXIT_FAILURE);
}
