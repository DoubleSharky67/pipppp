/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:09:40 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/08 16:42:49 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nb_lenght(long int n)
{
	long int	i;
	int			counter;

	i = 10;
	counter = 1;
	while (n / i != 0)
	{
		i *= 10;
		counter++;
	}
	return (counter);
}

static char	*ft_neg_itoa(int n)
{
	char		*str;
	long int	nb;
	int			i;

	nb = (long)n * -1;
	str = malloc(sizeof(char) * (ft_nb_lenght(nb) + 2));
	if (!str)
		return (NULL);
	str[0] = '-';
	i = ft_nb_lenght(nb);
	while (i > 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	str[ft_nb_lenght(n) + 1] = '\0';
	return (str);
}

static char	*ft_pos_itoa(int n)
{
	char	*str;
	int		i;
	int		nb;

	nb = n;
	str = malloc(sizeof(char) * (ft_nb_lenght(n) + 1));
	if (!str)
		return (NULL);
	i = ft_nb_lenght(n) - 1;
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	str[ft_nb_lenght(n)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n < 0)
	{
		str = ft_neg_itoa(n);
	}	
	else
	{
		str = ft_pos_itoa(n);
	}
	return (str);
}
