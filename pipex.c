/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/04/29 17:13:07 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void wait_childs(t_pids pids) {
    size_t i;

    i = 0;
    while(i < pids.size)
        waitpid(pids.ids[i++], 0, 0);
}

int **create_pipes(size_t count)
{
    size_t i;
    int **pipes;
    
    i = 0;
    pipes = malloc(count * sizeof(int *));
    if (!pipes)
        on_error();
    while (i < count)
    {
        pipes[i] = malloc(2 * sizeof(int));
        if (!pipes[i])
            on_error();
        if (pipe(pipes[i]) == -1)
            on_error();
        i++;
    }
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
int execute_cmd2(char *cmd[], int read_fd, int write_fd, int fd_close[])
{
    int pid;
    int i;
    pid = fork();
    if (pid)
        return (pid);
    i = 0;
    while (i < 2)
    {
        if (fd_close[i] != -1)
            close(fd_close[i]);
        i++;
    }
    dup2(read_fd, STDIN_FILENO); 
    close(read_fd);   
    dup2(write_fd, STDOUT_FILENO);
    close(write_fd);
    execve(cmd[0], cmd, 0);
    on_error();
}

    // if (cmds.size == 2)
    // {
    //     execute_cmd2(cmds.list[0], files.in_fd, pipes[0][1], pipes[0][0]);
    //     execute_cmd2(cmds.list[1], pipes[0][0], files.out_fd, pipes[0][1]);
    //     return ;
    // }
    
void    execute_all(t_cmds cmds, t_files files, int **pipes)
{
    size_t i;
    int fd_close[2];
    
    i = 0;
    while (i < cmds.size)
    {

        if (i == 0)
        {
            fd_close[0] = pipes[i][0];
            fd_close[1] = -1;
            execute_cmd2(cmds.list[i], files.in_fd, pipes[i][1], fd_close);
        }
        else if (i == cmds.size - 1)
        {
            fd_close[0] = pipes[i - 1][1];
            fd_close[1] = -1;
            execute_cmd2(cmds.list[i], pipes[i - 1][0], files.out_fd,fd_close);
        }
        else
        {
            fd_close[0] = pipes[i - 1][1];
            fd_close[1] = pipes[i][0];
            execute_cmd2(cmds.list[i], pipes[i - 1][0], pipes[i][1], fd_close);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_cmds cmds;
    int **pipes;
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

