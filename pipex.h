/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:17:42 by helarras          #+#    #+#             */
/*   Updated: 2024/05/07 00:40:00 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct files
{
	int		in_fd;
	int		out_fd;
}			t_files;

typedef struct cmds
{
	size_t	size;
	char	***list;
}			t_cmds;

typedef struct rw_ends
{
	int		rw[2];
	int		pi[2];
}			t_rw_ends;

t_files		get_files(char **data, size_t size, int heredoc);
char		**get_cmds_str(char **data, size_t size);
int			execute_cmds(t_cmds cmds, t_files files, char **env);
void		wait_childs(int childs);
char		*get_env_path(char **env);
int			set_cmds_path(t_cmds *cmds, char **paths);
t_cmds		split_cmds(char **cmds_str);
void		error_exit(void);
char		**split_path(char **env);
char		**parse_str(char *str);
char		**get_cmds_str(char **data, size_t size);


int        handle_error(int status, char *cmd);
void        set_paths(t_cmds *cmds, char **paths);
#endif