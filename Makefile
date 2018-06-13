# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:57:47 by igaliuk           #+#    #+#              #
#    Updated: 2018/03/04 19:13:01 by igaliuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = igaliuk.filler
NAME2 = visualizator.filler

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = ft_error_frees_filler.c \
	ft_read_map_token.c
SRC1 = filler.c \
	ft_processing_map.c \
	ft_processing_token.c
SRC2 = filler_visualizator.c \
	ft_write_map_token.c

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(OBJ)
	make -C libft
	@echo "       Compiling project...."
	@$(CC) $(FLAG) libft/libft.a -o $@ $^
	@echo "                                  Done!\n"

$(NAME2): $(OBJ2) $(OBJ)
	@echo "       Compiling bonus...."
	@$(CC) $(FLAG) libft/libft.a -o $@ $^
	@echo "                                  Done!\n"

%.o: %.c
	@$(CC) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ) $(OBJ1) $(OBJ2)
	make clean -C libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft
	
	@echo "\n       Objects of project were deleted.\n"
	@echo "       Binary file was deleted.\n"

re: fclean all
