/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/05/05 12:56:50 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"


void    print_cmds(t_cmds cmds)
{
    int i = 0;

    while (cmds.list[i])
    {
        printf("%s\n", cmds.list[i][0]);
        i++;
    }
}

void    check_args(int size)
{
    if (size < 4)
    {
        ft_printf("pipex: not enough arguments!\n");
        exit(EXIT_FAILURE);
    }
}

int is_heredoc(char *arg)
{
    return (ft_strncmp(arg, "here_doc", 8) == 0);
}


int main(int argc, char **argv, char **env)
{
    t_cmds  cmds;
    t_files files;
    char    **cmds_str;
    char    **paths;
    int     childs;

    check_args(argc - 1);
    if (is_heredoc(argv[1]))
    {
        files = get_files(argv + 1, argc - 1, 1);
        cmds_str = get_cmds_str(argv + 2, argc - 2);
    }
    else
    {
        files = get_files(argv + 1, argc - 1, 0);
        cmds_str = get_cmds_str(argv + 1, argc - 1);
    }
    paths = split_path(env);
    cmds = split_cmds(cmds_str);
    set_cmds_path(&cmds, paths);
    childs = execute_cmds(cmds, files, env);
    wait_childs(childs);
    system("leaks -q pipex");
}




