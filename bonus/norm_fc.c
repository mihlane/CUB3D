/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:02:04 by mhabibi-          #+#    #+#             */
/*   Updated: 2023/04/09 17:45:47 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	fill_and_free2(t_cub *cub, char *num, int i)
{
	cub->f[i] = ft_atoi(num);
	free(num);
	num = NULL;
}

char	*join_norm(char *num, char str)
{
	char	*num2;

	num2 = get_current_char_as_string(str);
	num = ft_strjoin2(num, num2);
	return (num);
}
