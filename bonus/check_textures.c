/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:38:32 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 17:43:35 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free (s2);
	return (str);
}

void	check_north(char *str, int i, t_cub *cub)
{
	char	*north;
	int		fd;

	if (cub->north != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	north = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(north, O_RDONLY, 0777);
	if (fd < 0)
		print_error();
	cub->north = ft_strdup(north);
	free (north);
	cub->conditions -= 1;
}

void	check_south(char *str, int i, t_cub *cub)
{
	char	*south;
	int		fd;

	if (cub->south != NULL)
		print_error();
	i++;
	if (str[i] != 'O' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	south = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(south, O_RDONLY, 0777);
	if (fd < 0)
		print_error();
	cub->south = ft_strdup(south);
	free (south);
	cub->conditions -= 2;
}

void	check_west(char *str, int i, t_cub *cub)
{
	char	*west;
	int		fd;

	if (cub->west != NULL)
		print_error();
	i++;
	if (str[i] != 'E' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	west = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(west, O_RDONLY, 0777);
	if (fd < 0)
		print_error();
	cub->west = ft_strdup(west);
	free (west);
	cub->conditions -= 3;
}

void	check_east(char *str, int i, t_cub *cub)
{
	char	*east;
	int		fd;

	if (cub->east != NULL)
		print_error();
	i++;
	if (str[i] != 'A' || (str[i + 1] != ' ' && str[i + 1] != '\t'))
		print_error();
	i += 2;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	east = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(east, O_RDONLY, 0777);
	if (fd < 0)
		print_error();
	cub->east = ft_strdup(east);
	free (east);
	cub->conditions -= 4;
}
