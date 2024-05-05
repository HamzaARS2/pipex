/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writestr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:08:42 by helarras          #+#    #+#             */
/*   Updated: 2024/01/09 16:26:23 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	writestr(char *str)
{
	size_t	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		write(1, str + (i++), 1);
	return (i);
}
