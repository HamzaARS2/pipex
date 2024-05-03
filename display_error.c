/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:38:17 by helarras          #+#    #+#             */
/*   Updated: 2024/05/03 22:17:21 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    display_error(char *title, char *msg)
{
    write(2, title, ft_strlen(title));
    write(2, msg, ft_strlen(msg));
}