/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:10:44 by helarras          #+#    #+#             */
/*   Updated: 2024/05/05 12:23:16 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	writestr(char *str);
size_t	writechar(char c);
size_t	writei_base(int number, char *base, unsigned int nbase);
size_t	writeul_base(unsigned long number, char *base, unsigned int nbase);
#endif
