# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 12:46:43 by mhabibi-          #+#    #+#              #
#    Updated: 2023/03/21 17:51:07 by user             ###   ########.fr        #
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

CC = cc

# FLAGS = -Wall -Wextra -Werror 

all : $(NAME)
$(NAME) : $(SRCS) 
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all