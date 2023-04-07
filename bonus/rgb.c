/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:48:56 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/07 02:18:30 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_count(unsigned long a)
{
	int	count;

	count = 0;
	while (a >= 16)
	{
		a = a / 16;
		count++;
	}
	return (count);
}

char	ft_checkkk(int r)
{
	if (r >= 10 && r <= 15)
		return (r + 55);
	else
		return ((int)r % 16 + '0');
}

char	*ft_hexup(int n)
{
	int		f;
	int		r;
	int		count;
	char	*str;
	int		count2;

	f = n;
	count = ft_count(f);
	str = malloc(count + 1);
	str[count + 1] = '\0';
	while (f > 15)
	{
		r = f % 16;
		f = f / 16;
		str[count] = ft_checkkk(r);
		count--;
	}
	str[count] = ft_checkkk(f);
	return (str);
}
