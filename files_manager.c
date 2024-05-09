/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:39 by helarras          #+#    #+#             */
/*   Updated: 2024/05/09 15:05:23 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_heredoc(char *limiter)
{
	char	*line;
	int		quit;
	char	*all_lines;

	quit = 0;
	all_lines = 0;
	while (!quit)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (!ft_strncmp(line, limiter, ft_strlen(line) - 1))
			quit = 1;
		else
			all_lines = strcombine(all_lines, line);
	}
	free(line);
	if (!all_lines)
		exit(0);
	return (all_lines);
}

int	get_heredoc_input(char *limiter)
{
	int		p[2];
	char	*data;

	data = read_heredoc(limiter);
	pipe(p);
	write(p[1], data, ft_strlen(data));
	free(data);
	close(p[1]);
	return (p[0]);
}

int	open_input_file(char **data, int heredoc)
{
	int	in_fd;

	if (heredoc)
		return (get_heredoc_input(data[1]));
	in_fd = open(data[0], O_RDONLY);
	if (in_fd == -1)
		perror(data[0]);
	return (in_fd);
}

int	open_output_file(char *path, int heredoc)
{
	int	out_fd;

	if (heredoc)
		out_fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		out_fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out_fd == -1)
		error_exit(path);
	return (out_fd);
}

t_files	get_files(char **data, size_t size, int heredoc)
{
	t_files	files;

	files.in_fd = open_input_file(data, heredoc);
	files.out_fd = open_output_file(data[size - 1], heredoc);
	return (files);
}
