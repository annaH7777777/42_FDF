/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:46:22 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 15:46:26 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	if (!(p = malloc(total)))
		return (NULL);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return ((void*)p);
}
