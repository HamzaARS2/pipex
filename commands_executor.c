/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:20:32 by helarras          #+#    #+#             */
/*   Updated: 2024/05/08 13:32:33 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int fd[])
{
	if (fd[0] != STDIN_FILENO && fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

t_rw_ends	get_rw_ends(t_rw_ends rw_ends, t_files files, size_t i, size_t size)
{
	if (i == 0)
	{
		pipe(rw_ends.pi);
		rw_ends.rw[0] = files.in_fd;
		rw_ends.rw[1] = rw_ends.pi[1];
	}
	else if (i == size - 1)
	{
		rw_ends.rw[0] = rw_ends.pi[0];
		rw_ends.rw[1] = files.out_fd;
	}
	else
	{
		rw_ends.rw[0] = rw_ends.pi[0];
		pipe(rw_ends.pi);
		rw_ends.rw[1] = rw_ends.pi[1];
	}
	return (rw_ends);
}

void	duplicate_fds(t_rw_ends rw_ends)
{
	if (rw_ends.rw[0] != STDIN_FILENO)
		dup_fd(rw_ends.rw[0], STDIN_FILENO);
	dup_fd(rw_ends.rw[1], STDOUT_FILENO);
}

int	run_cmd(t_rw_ends rw_ends, char *cmd[], char **env)
{
	if (rw_ends.rw[0] == -1)
	{
		close_fds(rw_ends.rw);	
		return (0);
	}
	if (fork())
	{
		close_fds(rw_ends.rw);
		return (1);
	}
	duplicate_fds(rw_ends);
	close_fds(rw_ends.rw);
	close_fds(rw_ends.pi);
	execve(cmd[0], cmd, env);
	error_exit("pipex");
	return (1);
}

int	execute_cmds(t_cmds cmds, t_files files, char **env)
{
	size_t		i;
	size_t		childs;
	t_rw_ends	rw_ends;

	i = 0;
	childs = 0;
	while (i < cmds.size)
	{
		rw_ends = get_rw_ends(rw_ends, files, i, cmds.size);
		childs += run_cmd(rw_ends, cmds.list[i], env);
		i++;
	}
	close(files.in_fd);
	close(files.out_fd);
	return (childs);
}
