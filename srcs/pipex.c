/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:09 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/12/19 16:23:54 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

void	ft_output_pipe(char **argv, char **envp, t_data *data)
{
	dup2(data->fd_output, 1);
	//---
	close(data->fd_input);
	close(data->fd_output);
	close(data->p[0]);
	//---
	if (!ft_find_path(argv, envp, data))
		exec_error("Command error");
	execve(data->path, data->cmd, envp);	
}

void	ft_pipe(char **argv, char **envp, t_data *data)
{
	if (pipe(data->p) < 0)
		exec_error("Pipe error");
	data->pid = fork();
	if (data->pid < 0)
		exec_error("Fork error");
	if (!data->pid)
	{
		close(data->p[0]);
		dup2(data->p[1], 1);
		//----
		close(data->fd_input);
		close(data->fd_output);
		close(data->p[1]);
		//----
		if (!ft_find_path(argv, envp, data))
			exec_error("Command error");
		execve(data->path, data->cmd, envp);
	}
	else
	{
		wait(NULL);
		close(data->p[1]);
		dup2(data->p[0], 0);
		close(data->p[0]);
	}
}

int     ft_init_data(int argc, char **argv, t_data *data)
{
	data->nb_cmd = argc - 3;
	data->current_cmd = 1;
	data->fd_input = open(argv[1], O_RDONLY);
	data->fd_output = open(argv[data->nb_cmd + 2]
		, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_input < 0 || data->fd_output < 0)
		return (0);
	return (1);
}



int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		return (input_error());
	//ajouter heredoc
	if (!ft_init_data(argc, argv, &data))
		return (file_error());
	dup2(data.fd_input, 0);
	while (data.current_cmd < data.nb_cmd)
	{
		ft_pipe(argv, envp, &data);
		data.current_cmd += 1;
	}
	ft_output_pipe(argv, envp, &data);
	return (0);
}
