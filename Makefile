# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:08:44 by tlima-de          #+#    #+#              #
#    Updated: 2025/01/06 16:15:40 by tlima-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = cub3d

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilib/minilibx-linux

# Diretórios
SRCS_DIR = src
OBJS_DIR = obj
LIB_DIR = lib/minilibx-linux

# Arquivos fontes e objetos
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
TOTAL_SRCS = $(words $(SRCS))

# Bibliotecas
LIBS = -L$(LIB_DIR) -lmlx -lm -lX11 -lXext

# Cores para saída
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
BLUE = \033[34m
CYAN = \033[36m

# Variável para controle do progresso
CURRENT_PROGRESS = 0

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(CYAN)Linking $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@printf "$(GREEN)Build complete!$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@
	$(eval CURRENT_PROGRESS=$(shell echo $$(($(CURRENT_PROGRESS)+1))))
	@printf "$(YELLOW)loading [$(shell printf '#%.0s' $$(seq 1 $(CURRENT_PROGRESS)))]$(RESET)\n"

clean:
	@printf "$(RED)Cleaning objects...$(RESET)\n"
	rm -rf $(OBJS_DIR)

fclean: clean
	@printf "$(RED)Cleaning executable...$(RESET)\n"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
