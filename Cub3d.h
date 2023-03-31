/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:47:41 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/03/31 02:07:35 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_cub
{
	char	**map;
	int		n_lines;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		f[2];
	int		c[2];
	int		check;
	int		check2;
	int		conditions;
	int		camma;
	int		px;
	int		py;
	int		nump;
	char	player;

}t_cub;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *str, size_t start, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void    print_error(void);
char	**ft_split(char *s, char c);
int     ft_strcmp(char *s1, char *s2);
void    check_north(char *str, int i, t_cub *cub);
void    check_east(char *str, int i, t_cub *cub);
void    check_west(char *str, int i, t_cub *cub);
void    check_south(char *str, int i, t_cub *cub);
void    check_ceil(char *str, int i, t_cub *cub);
void    check_floor(char *str, int i, t_cub *cub);
int	ft_atoi(const char *str);
char	*ft_strtrim(char *s1, char *set);

#endif