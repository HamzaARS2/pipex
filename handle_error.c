#include "pipex.h"

int handle_error(int status, char *cmd)
{
    if (!status)
        return (status);
    if (status == 'F')
        ft_printf("pipex : command not found : %s\n", cmd);
    else if (status == 'X')
        ft_printf("pipex : permission denied : %s\n", cmd);
    else
        ft_printf("pipex : unknown error occured!\n");
    return (status);
}