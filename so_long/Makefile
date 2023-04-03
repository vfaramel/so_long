# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 07:52:17 by vfaramel          #+#    #+#              #
#    Updated: 2023/03/29 22:43:54 by vfaramel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_split.c libft/ft_calloc.c libft/ft_bzero.c update.c \
		get_key.c get_images.c libft/ft_itoa.c map.c make_move.c main_game.c
CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= gcc
NAME	= so_long
all		: $(NAME)
$(NAME)	: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean	:
fclean	: clean
	rm -f $(NAME)
re	: fclean all
