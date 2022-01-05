/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:07:40 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 19:07:42 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t realsize;

	i = 0;
	j = 0;
	while (dst[i])
	{
		i++;
	}
	if (ft_strlen(dst) >= dstsize)
		realsize = ft_strlen(src) + dstsize;
	else
		realsize = ft_strlen(src) + ft_strlen(dst);
	while (i + 1 < dstsize && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (realsize);
}
