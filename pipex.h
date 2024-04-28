#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct files {
    int in_fd;
    int out_fd;
} t_files;

t_files get_files(char **data, size_t size);
char    **get_cmds(char **data, size_t size);





#endif