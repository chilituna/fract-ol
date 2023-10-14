# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 19:59:01 by aarponen          #+#    #+#              #
#    Updated: 2023/10/11 18:13:14 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

INCLUDES = -I./includes -I./Libft/ -I./MLX42/
LIBS = -ldl -lglfw -pthread -lm
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/libmlx42.a

SRC_DIR = src
SRC_FILES = fractol.c init.c calc.c draw.c hooks.c
OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $^ -L$(MLX_DIR) $(LIBS) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: clean all

.PHONY: all clean fclean re