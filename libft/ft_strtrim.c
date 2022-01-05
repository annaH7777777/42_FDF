/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:25:54 by annharut          #+#    #+#             */
/*   Updated: 2021/02/27 19:25:55 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;
	int		strsize;
	char	*p;

	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	strsize = ((end - begin + 1) > 0) ? (end - begin + 1) : 1;
	p = malloc(strsize);
	if (!p)
		return (NULL);
	i = 0;
	while (i < strsize)
	{
		p[i] = s1[begin];
		i++;
		begin++;
	}
	p[i] = '\0';
	return (p);
}
