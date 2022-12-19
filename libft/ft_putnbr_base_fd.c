/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:16:43 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/13 16:47:29 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long long nb, char *base, int fd)
{
	char	c;
	size_t	nbr;

	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	nbr = (size_t)nb;
	if (nbr >= ft_strlen(base))
		ft_putnbr_base_fd(nbr / ft_strlen(base), base, fd);
	c = base[nbr % ft_strlen(base)];
	ft_putchar_fd(c, fd);
}
