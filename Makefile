# Nome do executável
NAME = cub3d

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilib/minilibx-linux -Ilib/libft

# Diretórios
SRCS_DIR = src
OBJS_DIR = obj
LIBMLX_DIR = lib/minilibx-linux
LIBFT_DIR = lib/libft

# Arquivos fontes e objetos
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# Bibliotecas
LIBS = -L$(LIBMLX_DIR) -lmlx -lm -lX11 -lXext -L$(LIBFT_DIR) -lft

# Cores para saída
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
BLUE = \033[34m
CYAN = \033[36m

# Regras
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(LIBMLX_DIR)/libmlx.a
	@printf "$(CYAN)Linking $(NAME)...$(RESET)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@printf "$(GREEN)Build complete!$(RESET)\n"

$(LIBFT_DIR)/libft.a:
	@printf "$(CYAN)Compiling libft...$(RESET)\n"
	@make -C $(LIBFT_DIR)

$(LIBMLX_DIR)/libmlx.a:
	@printf "$(CYAN)Compiling MinilibX...$(RESET)\n"
	@make -C $(LIBMLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED)Cleaning objects...$(RESET)\n"
	rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean

fclean: clean
	@printf "$(RED)Cleaning executable and libraries...$(RESET)\n"
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(LIBMLX_DIR)/libmlx.a

re: fclean all

.PHONY: all clean fclean re
