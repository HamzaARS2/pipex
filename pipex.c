/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/05/02 20:38:11 by helarras         ###   ########.fr       */
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


int main(int argc, char **argv, char **env)
{
    t_cmds  cmds;
    t_files files;
    char    **cmds_str;
    char    **paths;

    if (argc - 3 < 2)
    {
        display_error("pipex: ", "Not enough arguments!");
        return (EXIT_FAILURE);
    }
    files = get_files(argv + 1, argc - 1);
    cmds_str = get_cmds_str(argv + 1, argc - 1);
    paths = split_path(env);
    cmds = split_cmds(cmds_str);
    set_cmds_path(&cmds, paths);
    int childs = execute_cmds(cmds, files, env);
    wait_childs(childs);
    
    
   system("leaks -q pipex");
}


// int main(int argc, char **argv, char **env)
// {
//     t_cmds cmds;
//     t_pipes pipes;
//     t_files files = get_files(argv + 1, argc - 1);
//     char    **cmds_str = get_cmds_str(argv + 1, argc - 1);

//     cmds = split_cmds(cmds_str, env);
//     cmds = find_cmds_path(cmds);
//     pipes = create_pipes(cmds.size - 1);
//     int childs = execute_cmds(cmds, files, pipes);
//     close_pipes(pipes);
//     close(files.in_fd);
//     close(files.out_fd);
//     wait_childs(childs);
    
    
// }



