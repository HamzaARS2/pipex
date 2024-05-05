/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:58:39 by helarras          #+#    #+#             */
/*   Updated: 2024/05/05 11:45:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_heredoc(char *limiter)
{
	char	*line;
    size_t  limiter_size;
	char	*all_lines;

    limiter_size = ft_strlen(limiter);
	write(1, "pipe heredoc> ", 14);
	line = get_next_line(0);
	all_lines = line;
	while (line && ft_strncmp(line, limiter, limiter_size))
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		all_lines = strcombine(all_lines, line);
	}
	return (all_lines);
}

int	get_heredoc_input(char *limiter)
{
	int p[2];
	char *data;

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
		error_exit();
	return (in_fd);
}

int	open_output_file(char *path, int heredoc)
{
	int	out_fd;

	if (heredoc)
		out_fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0777);
	else
		out_fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (out_fd == -1)
		error_exit();
	return (out_fd);
}



t_files	get_files(char **data, size_t size, int heredoc)
{
	t_files	files;

	if (size < 3)
		return ((t_files){0});
	files.in_fd = open_input_file(data, heredoc);
	files.out_fd = open_output_file(data[size - 1], heredoc);
	return (files);
}


