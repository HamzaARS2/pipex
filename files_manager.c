/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:39 by helarras          #+#    #+#             */
/*   Updated: 2024/04/25 12:52:42 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freeall(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

char    **get_files_path(char **data, size_t size)
{
    char **files_path;

    if (size < 2)
        return (0);
    files_path = malloc(3 * sizeof(char *));
    if (!files_path)
        return (0);
    files_path[0] = ft_strdup(data[0]);
    if (!files_path[0])
        return (0);
    files_path[1] = ft_strdup(data[size - 1]);
    if (!files_path[1])
    {
        freeall(files_path, 0);
        return (0);
    }
    
    return (files_path);
}

t_files get_files(char **paths)
{
    t_files files;

    files.in_fd = open_file(paths[0], O_RDONLY);
    if (files.in_fd == -1)
    {
        freeall(paths, 1);
        perror("")
    }
    files.out_fd = open_file(paths[1], O_RDONLY);

}

int open_file(char *path, int flag)
{
    int fd;

    fd = open(path, flag);
    if (fd == -1)
        return (fd);
    return (fd);
}

char    **get_cmds(char **data, size_t size)
{
    char **cmds;
    int i;
    int end;
    
    if (size < 3)
        return (0);
    cmds = malloc((size - 1) * sizeof(char *));
    if (!cmds)
        return (0);
    i = 0;
    end = size - 1;
    while (++i < end)
    {
        cmds[i - 1] = ft_strdup(data[i]);
        if (!cmds[i - 1])
        {
            freeall(cmds, i - 2);
            return (0);
        }
    }
    cmds[i - 1] = 0;
    return (cmds);
}