/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:52:40 by helarras          #+#    #+#             */
/*   Updated: 2024/05/05 12:13:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freeall(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

char    *get_env_path(char **env)
{
    int i = 0;

    while (env[i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
            return (env[i] + 5);
        i++;
    }
    return (0);
}

char    **split_path(char **env)
{
    size_t i;
    char *temp;
    char **paths;

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


static int assign_path(char **cmd, char **paths)
{
    size_t i;
    char *cmd_path;

    i = 0;
    if (!cmd || !(*cmd))
        return ('A');
    while (paths[i])
    {
        cmd_path = ft_strjoin(paths[i], *cmd);
        if (!cmd_path)
            return ('A');
        if (access(cmd_path, F_OK) != -1)
        {
            free(*cmd);
            *cmd = cmd_path;
            return ('S');
        }
        free(cmd_path);
        i++;
    }
    ft_printf("pipex: command not found: %s\n", *cmd);
    return ('F');
}

int set_cmds_path(t_cmds *cmds, char **paths)
{
    int i;
    int status;
    int error;
    
    i = 0;
    error = 0;
    if (!paths)
        return ('A');
    while (cmds->list[i])
    {
        status = assign_path(cmds->list[i], paths);
        if (status == 'F')
            error = status;
        else if (status == 'A')
            error = status;
        i++;
    }
    if (error)
        exit(1);
    return ('S');
}