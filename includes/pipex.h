/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:25:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/12/19 14:32:39 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct n_data
{
	int	current_cmd;
	int	nb_cmd;
	int	pipe1[2];
//	int	pipe2[2];
	int	pid;
	int	fd_input;
	int	fd_output;
	char	**cmd;
	char	*path;
	char	**path_tab;
}	t_data;

//---UTILS FUNCTIONS---

void    ft_free_tab(char **tab);
void    ft_free_data(t_data *data);
int ft_strncmp_pipex(const char *s1, const char *s2, int n);
char    *ft_strjoin_sep(const char *s1, const char *s2, char sep);

//---PARSE FUNCTIONS---

int ft_find_path(char **argv, char** envp, t_data *data);

//---ERROR FUNCTIONS---

int input_error();
int file_error();
int exec_error();

#endif
