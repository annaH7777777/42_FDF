/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 15:46:22 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 20:06:12 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
