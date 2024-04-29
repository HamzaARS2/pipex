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

static void	freelist(char ***arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

int execute_cmd(char *cmd[], int read_fd, int write_fd)
{
    int pid = fork();
    if (pid)
        return pid;
    dup2(read_fd, STDIN_FILENO); 
    close(read_fd);   
    dup2(write_fd, STDOUT_FILENO);
    close(write_fd);
    execve(cmd[0], cmd, 0);
    on_error();
}

t_cmds  split_cmds(char **cmds_str)
{
    size_t i;
    t_cmds cmds;
    i = 0;
    
    cmds.size = arrlen(cmds_str);
    cmds.list = malloc((cmds.size + 1) * sizeof(char **));
    if (!cmds.list)
        on_error();
    while (cmds_str[i])
    {
        cmds.list[i] = ft_split(cmds_str[i], ' ');
        if (!cmds.list[i])
        {
            freelist(cmds.list, i - 1);
            on_error();
        }
        i++;
    }
    cmds.list[cmds.size] = 0;
    return(cmds);
}

t_pids  run_cmds(char **cmds_str, t_files files)
{
    size_t i;
    t_pids pids;
    t_cmds cmds;

    i = 0;
    cmds = split_cmds(cmds_str);
    pids.ids = malloc(cmds.size * sizeof(int));
    if (!pids.ids)
        on_error();
    while (cmds.list[i])
    {
        pids.ids[i] = execute_cmd(cmds.list[i], files.in_fd, files.out_fd);
        i++;
    }
    pids.size = cmds.size;
    return (pids);
}

