/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/04/30 11:55:51 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void wait_childs(int childs) {
    size_t i;

    i = 0;
    while(i < childs)
    {
        printf("%i\n", i);
        if (wait(0) == -1)
            perror("waitpid");
        i++;
    }
}

t_pipes create_pipes(size_t count)
{
    size_t i;
    t_pipes pipes;
    
    i = 0;
    pipes.list = malloc(count * sizeof(int *));
    if (!pipes.list)
        on_error();
    while (i < count)
    {
        pipes.list[i] = malloc(2 * sizeof(int));
        if (!pipes.list[i])
            on_error();
        if (pipe(pipes.list[i]) == -1)
            on_error();
        i++;
    }
    pipes.size = count;
    return (pipes);
}

int execute_cmd2(char *cmd[], int read_fd, int write_fd, t_pipes pipes)
{
    int i;

    if (fork() == 0)
    {
        i = 0;
        dup2(read_fd, STDIN_FILENO); 
        dup2(write_fd, STDOUT_FILENO);
        close(read_fd);
        close(write_fd);
        while (i < pipes.size)
        {
            close(pipes.list[i][0]);
            close(pipes.list[i][1]);
            i++;
        }
        execve(cmd[0], cmd, 0);
        on_error();
    }
    return (1);
}

    
int  execute_all(t_cmds cmds, t_files files, t_pipes p)
{
    size_t i;
    int childs;
    
    childs = 0;
    if (cmds.size == 1)
        return (execute_cmd2(cmds.list[0], files.in_fd, files.out_fd, p));
    i = 0;
    while (i < cmds.size)
    {
        if (i == 0)
            childs += execute_cmd2(cmds.list[i], files.in_fd, p.list[i][1], p);
        else if (i == cmds.size - 1)
            childs += execute_cmd2(cmds.list[i], p.list[i - 1][0], files.out_fd, p);
        else
            childs += execute_cmd2(cmds.list[i], p.list[i - 1][0], p.list[i][1], p);
        i++;
    }
    return (childs);
}

int main(int argc, char **argv)
{
    t_cmds cmds;
    t_pipes pipes;
    t_files files = get_files(argv + 1, argc - 1);
    char    **cmds_str = get_cmds_str(argv + 1, argc - 1);

    cmds = split_cmds(cmds_str);
    pipes = create_pipes(cmds.size - 1);
    int childs = execute_all(cmds, files, pipes);
    for(int i = 0; i < pipes.size; i++)
    {
        close(pipes.list[i][0]);
        close(pipes.list[i][1]);
    }
    close(files.in_fd);
    close(files.out_fd);
    printf("childs = %i\n", childs);
    wait_childs(childs);
    // close(files.in_fd);
    // close(files.out_fd);
    // wait_childs(childs);
    // wait_childs(pids);
    
    
}



// int main()
// {
//     int latest_pid;
//     int pipe_fds[2];
//     int arr[] = {1,2,3,4,5,6};
//     int result;
//     int start;
//     int end;

//     result = 0;
//     pipe(pipe_fds);
//     latest_pid = create_child_process();
//     if (latest_pid == 0)
//     {
//         // child process
//         start = 0;
//         end = ((sizeof(arr) / sizeof(int)) / 2);
//     }
//     else
//     {
//         // parent process
//         start = ((sizeof(arr) / sizeof(int)) / 2);
//         end = (start * 2);
//         wait(NULL);
//     }
//     while (start < end)
//         result += arr[start++];
//     if (latest_pid == 0)
//         write(pipe_fds[1], &result, sizeof(int));
//     else
//     {
//         int data;
//         read(pipe_fds[0], &data, sizeof(int));
//         result += data;
//         printf("PARENT(%i) + CHILD(%i) = %i\n", result - data, data, result);
//     }
// }

