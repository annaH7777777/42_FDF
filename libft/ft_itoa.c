/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:55:55 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 15:55:57 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nbr)
{
	int l;

	l = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		l++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*tmp;
	long	nbr;

	nbr = n;
	i = 0;
	i = ft_intlen(nbr);
	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
		return (NULL);
	tmp[i] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
	}
	while (--i >= 0)
	{
		tmp[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		tmp[0] = '-';
	return (tmp);
}
