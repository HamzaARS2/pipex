/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:08 by helarras          #+#    #+#             */
/*   Updated: 2024/05/09 17:01:42 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int size, int heredoc)
{
	if ((heredoc && size >= 5) || (!heredoc && size >= 4))
		return ;
	ft_printf("pipex: not enough arguments!\n");
	exit(EXIT_FAILURE);
}

int	is_heredoc(char *arg)
{
	return (ft_strcmp(arg, "here_doc") == 0);
}

void	prepare_resources(char **data, int size, t_files *files,
		char ***cmds_str)
{
	int	heredoc;

	heredoc = is_heredoc(data[0]);
	check_args(size, heredoc);
	*files = get_files(data, size, heredoc);
	if (heredoc)
		*cmds_str = get_cmds_str(data + 1, size - 1);
	else
		*cmds_str = get_cmds_str(data, size);
}

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	t_files	files;
	char	**cmds_str;
	char	**paths;
	int		childs;

	prepare_resources(argv + 1, argc - 1, &files, &cmds_str);
	paths = split_path(env);
	cmds = split_cmds(cmds_str);
	set_paths(&cmds, paths);
	childs = execute_cmds(cmds, files, env);
	wait_childs(childs);
}
