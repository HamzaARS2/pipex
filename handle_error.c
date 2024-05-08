#include "pipex.h"

int handle_error(int status, char *cmd)
{
    if (!status)
        return (status);
    if (status == 'F')
        ft_printf("%s: command not found\n", cmd);
    else if (status == 'X')
        ft_printf("%s: permission denied\n", cmd);
    else
        ft_printf("%s: unknown error occured!\n");
    return (status);
}