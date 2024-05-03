/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:23:59 by helarras          #+#    #+#             */
/*   Updated: 2024/05/03 22:20:47 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	freelist(char ***arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

t_cmds  split_cmds(char **cmds_str)
{
    size_t i;
    t_cmds cmds;
    i = 0;
    
    cmds.size = arrlen(cmds_str);
    cmds.list = malloc((cmds.size + 1) * sizeof(char **));
    if (!cmds.list)
        error_exit();
    while (cmds_str[i])
    {
        cmds.list[i] = quote_split(cmds_str[i], ' ');
        if (!cmds.list[i])
        {
            freelist(cmds.list, i - 1);
            error_exit();
        }   
        i++;
    }
    cmds.list[cmds.size] = 0;
    return(cmds);
}
