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

typedef struct rw_ends {
    int rw[2];
    int pi[2];
} t_rw_ends;

t_files get_files(char **data, size_t size);
char    **get_cmds_str(char **data, size_t size);
int     execute_cmds(t_cmds cmds, t_files files, char **env);
void    wait_childs(int childs);
char    *get_env_path(char **env);
int     set_cmds_path(t_cmds *cmds, char **paths);
size_t  arrlen(char **arr);
t_cmds  split_cmds(char **cmds_str);
void    on_error();
void    display_error(char *cmd, char *msg);
char    **split_path(char **env);


#endif