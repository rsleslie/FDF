# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:54:33 by rleslie-          #+#    #+#              #
#    Updated: 2023/01/27 18:49:25 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = src/draw.c src/events.c src/main.c src/read_map.c src/utils.c
OBJ := ${.c=.o}
FLAGS = -lmlx -lm -lX11 -lXext -Imlx -lXext -Wall -Wextra -Werror
INCLUDES = libft/libft.a


all: $(NAME)

$(NAME):$(OBJ)
	@make -C libft
	cc $(SRCS) $(INCLUDES) $(FLAGS) -o $(NAME)

clean:
		@make fclean -C libft
		rm -rf ./src/*.o

fclean: clean
		rm -rf a.out
		rm -rf $(NAME)

re: fclean all
