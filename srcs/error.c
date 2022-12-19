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

int	exec_error()
{
	ft_putstr_fd("Execution error", 2);	
	return (1);
}
