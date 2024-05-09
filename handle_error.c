/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:11:49 by helarras          #+#    #+#             */
/*   Updated: 2024/05/09 17:11:52 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(int status, char *cmd)
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
