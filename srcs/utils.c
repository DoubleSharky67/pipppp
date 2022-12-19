/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:05:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/12/17 14:40:21 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_free_data(t_data *data)
{
	ft_free_tab(data->cmd);
	free(data->path);
}

int ft_strncmp_pipex(const char *s1, const char *s2, int n)
{
	int i;

	if (!s1 || !s2 || n <= 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
	{
		i++;
		if (i == n)
		return (1);
	}
	return (0);
}

char	*ft_strjoin_sep(const char *s1, const char *s2, char sep)
{
	char	*str;
	int	i;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = sep;
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + 1 + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + 1 + i] = '\0';
	return (str);
}
