# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorrao- <ptorrao-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 11:38:55 by ptorrao-          #+#    #+#              #
#    Updated: 2024/08/12 12:31:56 by ptorrao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE			= -I include
CC				= cc -g
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -fPIC
LIBFT			= libft/libft.a
NAME			= push_swap
SRC				= push_swap.c moves/push.c moves/swap.c moves/rotate.c moves/reverse.c \
				utils/utils.c validations/validate.c sort/sorting.c
OBJ 			= $(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ) $(LIBFT)
				$(CC) -o $@ $(OBJ) -Llibft -lft

%.o: 			%.c
				$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
				make -C libft

clean:
				$(RM) $(OBJ)
				make -C libft clean

fclean: 		clean
				$(RM) $(NAME)
				make -C libft fclean

re: 			fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/25705/checker_linux && chmod 777 checker_linux

visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	./bin/visualizer

.PHONY: 		all clean fclean re