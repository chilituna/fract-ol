# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 19:59:01 by aarponen          #+#    #+#              #
#    Updated: 2023/11/11 11:27:56 by aarponen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I./includes -I./Libft/ -I./MLX42/
LIBS = -ldl -lglfw -pthread -lm
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = MLX
MLX_LIB = $(MLX_DIR)/libmlx42.a

SRC_DIR = src
SRC_FILES = main.c check.c init.c calc.c color_handling.c hooks.c  \
	fractals.c error_and_exit.c colors.c
OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

.PHONY: all clean fclean re mlx

all: $(NAME)

mlx: 
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Creating $(MLX_DIR) directory..."; \
		mkdir -p $(MLX_DIR); \
	fi
	@if [ ! -f $(MLX_DIR)/libmlx42.a ]; then \
		echo "Downloading miniLibX..."; \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42; \
		cmake -B build; \
		cmake --build build -j4; \
		cp build/libmlx42.a ../MLX; \
		cp include/MLX42/MLX42.h ../MLX; \
		cd ..; \
		rm -rf MLX42; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $^ -L$(MLX_DIR) $(LIBS) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

cleanmlx:
	rm -rf $(MLX_LIB)
	rm -rf $(MLX_DIR)/MLX42.h

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
