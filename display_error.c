/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:38:17 by helarras          #+#    #+#             */
/*   Updated: 2024/05/02 11:38:29 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    display_error(char *cmd, char *msg)
{
    write(2, cmd, ft_strlen(cmd));
    write(2, msg, ft_strlen(msg));
}