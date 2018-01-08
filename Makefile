# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azybert <azybert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 08:55:53 by azybert           #+#    #+#              #
#    Updated: 2017/07/13 10:03:51 by azybert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = display.c \
		easy_algo.c \
		file_check.c \
		fillit.c \
		ft_taille.c \
		initialisation.c \
		print_error.c \
		struct_use.c \

OBJ = $(FILES:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(FILES)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
