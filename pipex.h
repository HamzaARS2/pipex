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


t_files get_files(char **data, size_t size);
char    **get_cmds(char **data, size_t size);
size_t  arrlen(char **arr);

#endif