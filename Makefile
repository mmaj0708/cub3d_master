# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/21 17:49:30 by mmaj              #+#    #+#              #
#    Updated: 2020/06/22 13:30:32 by mmaj             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = srcs/affect_floor_ceiling.c \
		srcs/affect_id_functions.c \
		srcs/affect_id_text.c \
		srcs/dealkey.c \
		srcs/draw_functions.c \
		srcs/ft_bmp.c \
		srcs/ft_check_closed_mp.c \
		srcs/ft_move_player.c \
		srcs/ft_read_map.c \
		srcs/ft_take_id_r.c \
		srcs/get_sprite_pos.c \
		srcs/get_verify_map.c \
		srcs/id_parsing.c \
		srcs/mlx_init.c \
		srcs/quit.c \
		srcs/set_params.c \
		srcs/sprite_matrix.c \
		srcs/spritecasting.c \
		srcs/utils_libft.c \
		srcs/utils_libft2.c \
		srcs/utils_mlx.c \
		srcs/utils.c \
		srcs/wallcasting_calculs.c \
		srcs/wallcasting.c \
		srcs/wolf.c \

OBJECTS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -I header -g -L ./

MLX = -lX11 -lXext -lm -lmlx

all : $(NAME)

$(NAME) :

	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MLX)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all