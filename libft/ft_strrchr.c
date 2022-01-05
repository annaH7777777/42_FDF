/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:23:34 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 19:23:36 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	symbol;

	symbol = (char)c;
	i = ft_strlen(s) + 1;
	str = (char*)s;
	while (--i >= 0)
	{
		if (str[i] == symbol)
		{
			return (str + i);
		}
	}
	if (str[i] == '\0' && symbol == '\0')
	{
		return (str + i);
	}
	return (NULL);
}
