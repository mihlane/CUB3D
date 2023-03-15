# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 12:46:43 by mhabibi-          #+#    #+#              #
#    Updated: 2023/03/14 14:46:08 by mhabibi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = CUB3D

SRCS  = main.c\
		ft_split.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_strcmp.c\
		ft_substr.c\

CC = cc

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)
$(NAME) : $(SRCS) 
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all