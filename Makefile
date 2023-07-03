# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:20:41 by lde-mich          #+#    #+#              #
#    Updated: 2023/06/30 12:29:53 by lde-mich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard gnl/*.c) $(wildcard *.c) $(wildcard errors/*.c)

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLX				= mlx-linux/libmlx.a -Lmlx-linux -lXext -lX11 -lm

NAME			= cub3D

$(NAME):		$(OBJS)
				make -C mlx-linux
				$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

all:			$(NAME)

clean:
				make clean -C mlx-linux
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus