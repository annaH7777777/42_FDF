/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:37:26 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 20:10:51 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strings_count(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue ;
		}
		while (s[k] != c && s[k])
			k++;
		i++;
	}
	return (i);
}

static int	freee(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
	}
	free(tab);
	return (-1);
}

static int	make_lines(char const *s, char **p, char c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue ;
		}
		while ((s[k] != c && s[k]))
		{
			k++;
			j++;
		}
		p[++i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!p)
			return (freee(p, i - 1));
		j = 0;
	}
	return (0);
}

static int	copy_lines(char const *s, char **p, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] == c)
		{
			k++;
			continue ;
		}
		while (s[k] != c && s[k])
		{
			p[i][j] = s[k];
			j++;
			k++;
		}
		p[i][j] = '\0';
		i++;
		j = 0;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		strcount;

	if (!s)
		return (NULL);
	strcount = ft_strings_count(s, c);
	p = (char **)malloc(sizeof(char *) * (strcount + 1));
	if (!p)
		return (NULL);
	p[strcount] = NULL;
	if (make_lines(s, p, c) == -1)
		return (NULL);
	copy_lines(s, p, c);
	return (p);
}
