#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct files {
    int in_fd;
    int out_fd;
} t_files;

typedef struct pids {
    size_t size;
    int *ids;
} t_pids;

typedef struct cmds {
    size_t  size;
    char    ***list;
} t_cmds;

typedef struct pipes {
    size_t size;
    int **list;
} t_pipes;

t_files get_files(char **data, size_t size);
char    **get_cmds_str(char **data, size_t size);
size_t  arrlen(char **arr);
int execute_cmd(char *cmd[], int read_fd, int write_fd);
t_cmds  split_cmds(char **cmds_str);
t_pids  run_cmds(char **cmds_str, t_files files);
void    on_error();


#endif