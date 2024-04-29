/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:39 by helarras          #+#    #+#             */
/*   Updated: 2024/04/29 07:05:57 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freeall(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

t_files get_files(char **data, size_t size)
{
    t_files files;
    
    if (size < 3)
        return ((t_files){0});
    files.in_fd = open(data[0], O_RDONLY);
    if (files.in_fd == -1)
        on_error();
    files.out_fd = open(data[size - 1], O_CREAT | O_RDWR , 0777);
    if (files.out_fd == -1)
        on_error();
    return (files);
}

char    **get_cmds_arg(char **data, size_t size)
{
    char **cmds_arg;
    int i;
    int end;
    
    if (size < 3)
        return (0);
    cmds_arg = malloc((size - 1) * sizeof(char *));
    if (!cmds_arg)
        return (0);
    i = 0;
    end = size - 1;
    while (++i < end)
    {
        cmds_arg[i - 1] = ft_strdup(data[i]);
        if (!cmds_arg[i - 1])
        {
            freeall(cmds_arg, i - 2);
            return (0);
        }
    }
    cmds_arg[i - 1] = 0;
    return (cmds_arg);
}

