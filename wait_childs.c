/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:16:07 by helarras          #+#    #+#             */
/*   Updated: 2024/05/01 15:16:31 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void wait_childs(int childs) 
{
    size_t i;

    i = 0;
    while(i < childs)
    {
        if (wait(0) == -1)
            perror("waitpid");
        i++;
    }
}
