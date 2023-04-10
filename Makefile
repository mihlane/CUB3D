NAME = Cub3d

MAIN = Cub3d.c

SRCS_RAYCASTING = RayCasting/Init.c RayCasting/Update.c RayCasting/Utils1.c RayCasting/Utils2.c RayCasting/Raycasting.c RayCasting/Projection.c \
	RayCasting/Texture.c RayCasting/Mini_map.c RayCasting/Init_door.c RayCasting/Vertical_Dist.c RayCasting/Horizontal_Dist.c RayCasting/Movement.c RayCasting/Events.c \

SRCS_PARSING  = Parsing/parsing.c\
		Parsing/ft_split.c\
		Parsing/get_next_line.c\
		Parsing/get_next_line_utils.c\
		Parsing/ft_strcmp.c\
		Parsing/ft_substr.c\
		Parsing/checks.c\
		Parsing/ft_atoi.c\
		Parsing/ft_strtrim.c\
		Parsing/check_textures.c\
		Parsing/floor_ceil.c\
		Parsing/norm_fc.c\
		Parsing/rgb.c\
		Parsing/check_inside_map.c\
		Parsing/check_map.c\
		Parsing/init_nd_fill.c\
		Parsing/firs_line.c\


HEADER = RayCasting/Cub3d.h Parsing/Parsing_Cub3d.h

OBJS_RAYCASTING = $(SRCS_RAYCASTING:.c=.o)

OBJS_PARSING = $(SRCS_PARSING:.c=.o)

OBJ_MAIN = $(MAIN:.c=.o)

CFLAGS = gcc -Wextra -Wall -Werror #-g3 -fsanitize=address

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS_RAYCASTING) $(OBJS_PARSING) $(OBJ_MAIN) $(HEADER)
	$(CFLAGS) $(MLX_FLAGS) $(OBJS_RAYCASTING) $(OBJS_PARSING) $(OBJ_MAIN) -o $(NAME)

.c.o:
	$(CFLAGS) -c $< -o ${<:.c=.o}

bonus: all

clean:
	rm -rf $(OBJS_RAYCASTING) $(OBJS_PARSING) $(OBJ_MAIN)

fclean:  clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
