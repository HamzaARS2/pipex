
#include "pipex.h"

void    on_error()
{
    perror("pipex");
    exit(EXIT_FAILURE);
}