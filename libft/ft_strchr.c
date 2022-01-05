/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:57:11 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 18:57:13 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	symbol;

	symbol = (char)c;
	i = 0;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == symbol)
		{
			return (str + i);
		}
		i++;
	}
	if (str[i] == '\0' && symbol == '\0')
	{
		return (str + i);
	}
	return (NULL);
}
