# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 12:46:43 by mhabibi-          #+#    #+#              #
#    Updated: 2023/04/09 17:32:15 by mhabibi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = CUB3D

SRCS  = main.c\
		ft_split.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_strcmp.c\
		ft_substr.c\
		checks.c\
		ft_atoi.c\
		ft_strtrim.c\
		check_textures.c\
		floor_ceil.c\
		norm_fc.c\
		rgb.c\
		check_inside_map.c\
		check_map.c\
		init_nd_fill.c\
		
CC = cc

 FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

all : $(NAME)
$(NAME) : $(SRCS) 
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all