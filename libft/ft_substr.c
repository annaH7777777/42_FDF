/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:29:59 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 19:30:01 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensubstr;
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(p = malloc(sizeof(char) * 1)))
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	lensubstr = ft_strlen(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
