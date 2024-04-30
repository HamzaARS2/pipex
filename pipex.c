/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/04/30 07:26:26 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void wait_childs(t_pids pids) {
    size_t i;

    i = 0;
    while(i < pids.size)
        waitpid(pids.ids[i++], 0, 0);
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
//   int p[2];
//         pipe(p);
//         if (fork() == 0)
//         {
//             close(p[0]);
//             dup2(files.in_fd, STDIN_FILENO); 
//             close(files.in_fd);   
//             dup2(p[1], STDOUT_FILENO);
//             execve(cmds.list[0][0], cmds.list[0], 0);
//             on_error();
//         }
        
//         if (fork() == 0)
//         {
//             close(p[1]);
//             dup2(p[0], STDIN_FILENO); 
//             close(p[0]);   
//             dup2(files.out_fd, STDOUT_FILENO);
//             close(files.out_fd);
//             execve(cmds.list[1][0], cmds.list[1], 0);
//             on_error();
//         }
int execute_cmd2(char *cmd[], int read_fd, int write_fd, t_pipes pipes)
{
    int pid;
    int i;
    pid = fork();
    if (pid)
        return (pid);
    i = 0;
    dup2(read_fd, STDIN_FILENO); 
    dup2(write_fd, STDOUT_FILENO);
    while (i < pipes.size)
    {
        close(pipes.list[i][0]);
        close(pipes.list[i][1]);
        i++;
    }
    execve(cmd[0], cmd, 0);
    on_error();
}

    
void    execute_all(t_cmds cmds, t_files files, t_pipes pipes)
{
    size_t i;
    int **p;

    if (cmds.size == 1)
    {
        execute_cmd2(cmds.list[0], files.in_fd, files.out_fd, pipes);
        return ;
    }
    
    p = pipes.list;
    i = 0;
    while (i < cmds.size)
    {
        if (i == 0)
            execute_cmd2(cmds.list[i], files.in_fd, p[i][1], pipes);
        else if (i == cmds.size - 1)
            execute_cmd2(cmds.list[i], p[i - 1][0], files.out_fd, pipes);
        else
            execute_cmd2(cmds.list[i], p[i - 1][0], p[i][1], pipes);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_cmds cmds;
    t_pipes pipes;
    t_files files = get_files(argv + 1, argc - 1);
    char    **cmds_str = get_cmds_str(argv + 1, argc - 1);

    cmds = split_cmds(cmds_str);
    pipes = create_pipes(cmds.size - 1);
    execute_all(cmds, files, pipes);

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

