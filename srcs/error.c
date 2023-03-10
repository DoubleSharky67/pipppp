/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:44:14 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/12/17 14:36:32 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int	input_error()
{
	ft_putstr_fd("Input error", 2);	
	return (1);
}

int	file_error()
{
	ft_putstr_fd("File error", 2);	
	return (1);
}

void	exec_error(char *str)
{
	perror(str);
	exit(-1);
}
