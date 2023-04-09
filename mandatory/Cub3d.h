/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:47:41 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 17:48:31 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
// # include "get_next_line.h"

typedef struct s_cub
{
	char	**map;
	int		start;
	int		n_lines;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		f[3];
	int		c[3];
	int		check;
	int		check2;
	int		conditions;
	int		camma;
	int		px;
	int		py;
	int		nump;
	char	player;
	char	door;
	int		line;
	int		length;
	int		width;
	int		floor_color;
	int		ceiling_color;
	char	**textures;
	char	**map2;

}t_cub;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *str, size_t start, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	print_error(void);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	check_north(char *str, int i, t_cub *cub);
void	check_east(char *str, int i, t_cub *cub);
void	check_west(char *str, int i, t_cub *cub);
void	check_south(char *str, int i, t_cub *cub);
void	check_ceil(char *str, int i, t_cub *cub);
void	check_floor(char *str, int i, t_cub *cub);
int		ft_atoi(const char *str);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split2(char *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
void	free_str2(char **str3, char *str, char *str2, t_cub *cub);
void	free_str(char **str3, char *str, char *str2, t_cub *cub);
void	fill_and_free(t_cub *cub, char *num, int i);
void	check_camma(char *str);
char	*get_current_char_as_string(char c);
void	fill_and_free2(t_cub *cub, char *num, int i);
char	*join_norm(char *num, char str);
int		rgbtoint(int r, int g, int b);
void	check_mapp(t_cub *cub, char **map, int z);
void	check_inside_map2(char **map, int z, t_cub *cub);
void	check_last_line(char **map, int z);
char	**get_fm(char **map, t_cub *cub, int i);
void	check_inside_map(char **map, t_cub *cub, int z, int k);
void	fill_map(t_cub *cub);
void	fill_text(t_cub *cub);
void	ft_init(t_cub *cub);
void	print_error(void);
int		get_max_len(char **map, int z, t_cub *cub);
void	check_char2(char **map, int z, int i, t_cub *cub);
void	check_char(char **map, int z, int i, t_cub *cub);
char	*get_fake_map(char *str, int k);
void	check_name(char *name);

#endif