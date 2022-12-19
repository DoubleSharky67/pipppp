/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:40:33 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/12/19 13:20:59 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

void    ft_get_paths(char **envp, t_data *data)
{
	int i;

	i = 0;
	while (!ft_strncmp_pipex(envp[i], "PATH=", 5))
		i++;
	data->path_tab = ft_split(envp[i] + 5, ':');
}

int ft_check_cmd(char **envp, t_data *data)
{
	char	*cmd_path;
	int		i;

	ft_get_paths(envp, data);
	if (!data->path_tab)
		return (0);
	i = 0;
	while (data->path_tab[i])
	{
		cmd_path = ft_strjoin_sep(data->path_tab[i], data->cmd[0], '/');
		if (!access(cmd_path, 0))
		{
			data->path = ft_strdup(cmd_path);
			free(cmd_path);
			ft_free_tab(data->path_tab);
			return (1);
		}
		free(cmd_path);
		i++;
	}
	ft_free_tab(data->path_tab);
	return (0);
}

int	ft_find_path(char **argv, char** envp, t_data *data)
{
	data->cmd = ft_split(argv[data->current_cmd + 1], ' ');
	if (!data->cmd)
		return (0);
	if (!ft_check_cmd(envp, data))
	{
		free(data->cmd);
		return (0);
	}
	return (1);
}
