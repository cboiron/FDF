# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 06:09:40 by cboiron           #+#    #+#              #
#    Updated: 2017/04/10 07:04:35 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c init_env.c image_printing.c raster.c print.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(OBJ) $(FLAG) libft/libft.a -lmlx -framework OpenGL -framework Appkit

clean :
	rm -rf $(OBJ)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all
