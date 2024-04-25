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


int create_child_process()
{
    static int pid;

    pid = -1;
    if (pid != 0)
        pid = fork();
    return (pid);
}



int main(int argc, char **argv)
{
   t_files files = get_files(argv + 1, argc - 1);
   char    **cmds = get_cmds(argv + 1, argc - 1);
   
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

