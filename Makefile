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

NAME = libwolf.a

SRCS = elements.c ft_getinfo.c ft_take_id.c map_parsing.c parsing.c utils.c mlx_init.c \
		wallcasting.c spritecasting.c dealkey.c

OBJECTS = elements.o ft_getinfo.o ft_take_id.o map_parsing.o parsing.o utils.o mlx_init.o \
		wallcasting.o spritecasting.o dealkey.o

INCLUDES = ../header/

all : $(NAME)

$(NAME) :

	@clang -g3 -fsanitize=address -Wall -Wextra -Werror -I$(INCLUDES) -g -L /usr/local/lib -c $(SRCS) -lX11 -lXext -lm -lmlx
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean : 
	@/bin/rm -f $(OBJECTS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all