/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:21:08 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 19:47:44 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	terminate(char *s)
{
	perror(s);
	exit(1);
}

float	max_number(float a, float b)
{
	float	c;

	if (a > b)
		c = a;
	else
		c = b;
	return (c);
}

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
