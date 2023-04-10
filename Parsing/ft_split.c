/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:04 by mhabibi-          #+#    #+#             */
<<<<<<< HEAD:Parsing/ft_split.c
/*   Updated: 2023/04/09 18:20:29 by ychaaibi         ###   ########.fr       */
=======
/*   Updated: 2023/04/09 17:44:30 by mhabibi-         ###   ########.fr       */
>>>>>>> 896aa80080c6943d717628c585d50dd98cca2d0e:bonus/ft_split.c
/*                                                                            */
/* ************************************************************************** */

#include "Parsing_Cub3d.h"

int	ft_wordcount(char *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j++;
			while (*s && *s != c)
				s++;
		}
	}
	return (j);
}

int	ft_wordlen(char const *s, char c)
{
	int	j;

	j = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		if (*s != c)
			j++;
		s++;
	}
	return (j);
}

static char	*ft_addword(const char *s, char c)
{
	char	*w;
	int		i;
	int		j;

	i = 0;
	j = ft_wordlen(s, c);
	w = malloc(j + 1);
	if (!w)
		return (0);
	while (s[i] != c && s[i] && j > 0)
	{
		w[i] = s[i];
		i++;
		j--;
	}
	w[i] = '\0';
	return (w);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab[j] = ft_addword(s + i, c);
			i += ft_wordlen(s + i, c);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split2(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab[j] = ft_addword(s + i, c);
			i += ft_wordlen(s + i, c);
			j++;
		}
	}
	tab[j] = 0;
	free (s);
	return (tab);
}
