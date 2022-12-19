/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:39:01 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/08 16:48:22 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_empty_tab(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static char	**ft_init_tab(char const *s, char c)
{
	int		i;
	int		counter;
	char	**tab;

	if (ft_empty_tab(s, c))
	{
		tab = malloc(sizeof(char *));
		tab[0] = NULL;
		return (tab);
	}
	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	tab = ft_calloc(counter + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*ft_fill_str(char *str, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = ft_init_tab(s, c);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && tab)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j] = ft_fill_str(tab[j], s + i, c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}
