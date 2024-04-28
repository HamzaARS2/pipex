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

t_pids  run_cmds(char **cmds_str, t_files files)
{
    int i = 0;
    t_pids pids;
    size_t  cmds_count;
    char ***cmds;

    cmds_count = arrlen(cmds_str);
    cmds = split_cmds(cmds_str, cmds_count);
    pids.ids = malloc(cmds_count * sizeof(int));
    while (cmds[i])
    {
        pids.ids[i] = execute_cmd(cmds[i], files.in_fd, files.out_fd);
        i++;
    }
    pids.size = cmds_count;
    return (pids);
}