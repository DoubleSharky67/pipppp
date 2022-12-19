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

void	ft_dup_rdwr(int fd_rd, int fd_wr)
{
	dup2(fd_rd, 0);
	dup2(fd_wr, 1);
}

void	ft_manage_fd(t_data *data)
{
	if (data->current_cmd == 1)
		ft_dup_rdwr(data->fd_input, data->pipe1[1]);
	else if (data->current_cmd == data->nb_cmd)
		ft_dup_rdwr(data->pipe1[0], data->fd_output);
}

void	ft_close_fd(t_data *data)
{
	close(data->pipe1[0]);
	close(data->pipe1[1]);
//	close(data->pipe2[0]);
//	close(data->pipe2[1]);
	if (data->fd_input != -1)	
		close(data->fd_input);
	if (data->fd_output != -1)	
		close(data->fd_output);
}

int	ft_child_process(char **argv, char **envp, t_data *data)
{
	data->pid = fork();
	if (data->pid < 0)
		return (0);
	if (!data->pid)
	{ 
		ft_putnbr_fd(data->current_cmd, 2); //f
		ft_putstr_fd("\n", 2);
		ft_manage_fd(data);
		ft_close_fd(data);
		if (!ft_find_path(argv, envp, data))
			return (0);
		//---------------------------
		ft_putstr_fd("Path :", 2);
		ft_putstr_fd(data->path, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("Cmd :", 2);
		ft_putstr_fd(data->cmd[0], 2);
		ft_putstr_fd("\n", 2);
		//----------------------------
		execve(data->path, data->cmd, envp);
		ft_putstr_fd("fefweeg", 2);  //wdqf
	}
	else 
		waitpid(-1, NULL, 0);
	return (1);
}

int	ft_pipe_loop(char **argv, char **envp, t_data *data)
{
	if (data->fd_input < 0)
	{
		perror("Wrong input file");
		data->current_cmd++;
	}
	while (data->current_cmd <= data->nb_cmd)
	{
		ft_child_process(argv, envp, data);
		ft_putnbr_fd(data->pid, 2); //ewg
		write(2, "\n", 1);
//		waitpid(data->pid, NULL, 0);
		data->current_cmd++;
	}
	return (1);
}

int	ft_init_data(int argc, char **argv, t_data *data)
{
	data->nb_cmd = argc - 3;
	data->current_cmd = 1;
	data->fd_input = open(argv[1], O_RDONLY);
	data->fd_output = open(argv[data->nb_cmd + 2]
		, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_output < 0)
		return (0);
	if (pipe(data->pipe1) < 0)
		return (0);
//	if (pipe(data->pipe2) < 0);
//		return (0);
//	close(pipe2[0]);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		return (input_error());
	if (!ft_init_data(argc, argv, &data))
		return (file_error());
	ft_pipe_loop(argv, envp, &data);
	ft_close_fd(&data);
	return (0);
}
