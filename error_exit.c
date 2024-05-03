
#include "pipex.h"

void    error_exit()
{
    perror("pipex");
    exit(EXIT_FAILURE);
}