/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/04/25 12:42:52 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void print_commands(char ***commands)
{
    // Print the commands and their arguments
    for (size_t i = 0; commands[i] != NULL; i++)
    {
        printf("Command %zu:\n", i + 1);
        for (size_t j = 0; commands[i][j] != NULL; j++)
        {
            printf("  Argument %zu: %s\n", j + 1, commands[i][j]);
        }
    }
}

int execute_cmd(char *cmd[], int read_fd, int write_fd)
{
    int pid = fork();
    if (pid)
        return pid;
    dup2(read_fd, STDIN_FILENO); 
    close(read_fd);   
    // dup2(write_fd, STDOUT_FILENO);
    // close(write_fd);
    execve(cmd[0], cmd, 0);
    perror("pipex");
    exit(EXIT_FAILURE);
}

char ***split_cmds(char **cmds_str, size_t cmds_count)
{
    size_t i;
    char ***result;
    i = 0;
    
    result = malloc((cmds_count + 1) * sizeof(char **));
    if (!result)
        return (0);
    while (cmds_str[i])
    {

        result[i] = ft_split(cmds_str[i], ' ');
        if (!result[i])
        {
            for (size_t j = 0; j < i; j++)
                free(result[j]);
            free(result);
            return (0);
        }
        i++;
    }
    result[cmds_count] = 0;
    return(result);
}

int *run_all_cmds(char **cmds_str, t_files files)
{
    int i = 0;
    int *pids;
    size_t  cmds_count;
    char ***cmds;

    cmds_count = arrlen(cmds_str);
    cmds = split_cmds(cmds_str, cmds_count);
    pids = malloc(cmds_count * sizeof(int));
    while (cmds[i])
    {
        pids[i] = execute_cmd(cmds[i], files.in_fd, files.out_fd);
        i++;
    }
    return (pids);
}
void wait_for_pids(int *pids) {
    size_t i;
    size_t num_pids;
    
    num_pids = sizeof(pids) / sizeof(pids[0]);
    printf("numpids: %zu\n", num_pids);
    i = 0;
    while(i <= num_pids)
    {
        waitpid(pids[i], NULL, 0);
        printf("Child process with PID %d has terminated\n", pids[i++]);
    }
}
int main(int argc, char **argv)
{
   t_files files = get_files(argv + 1, argc - 1);
   char    **cmds_str = get_cmds(argv + 1, argc - 1);
   
   int *pids = run_all_cmds(cmds_str, files);

    wait_for_pids(pids);

}

        // waitpid(pids[i],0,0);
//    while(i-- > 0)
//     printf("pid[%i] = %i\n",i,wait(NULL));

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

