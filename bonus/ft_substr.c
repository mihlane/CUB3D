/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:28:11 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/17 12:18:43 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

char *  ft_strlcpy(char *dest, const char *src, size_t size)
{
        size_t  i;
        size_t  b;

        b = 0;
        i = 0;
        while (src[b] != '\0')
        {
                b++;
        }
        if (size < 1)
                return (NULL);
        while ((src[i] != '\0') && (i < (size - 1)))
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

char	*ft_strdup(char *str)
{
	size_t 	i;
	size_t z;
	char	*str2;
	
	z = 0;
	i = ft_strlen(str);
	str2 = malloc(sizeof(char) * i + 1);
	while (z < i)
	{
		str2[z] = str[z];
		z++;
	}
	str2[z] = '\0';
	return (str2);
	
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	j;
	char	*str;
	
	if (!s)
		return (NULL);
	j = ft_strlen((char *)s);
	if (start > j)
		return (ft_strdup(""));
	if (j - start >= len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *) malloc(sizeof(char) *(j - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
