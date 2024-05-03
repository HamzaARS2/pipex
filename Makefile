CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c args_handler.c arrlen.c split_cmds.c commands_executor.c error_exit.c \
wait_childs.c path_finder.c display_error.c quote_split.c

LIBFT_DIR = libft/libft.a

NAME = pipex


$(NAME): $(SRCS) $(LIBFT_DIR)
	$(CC) $(SRCS) $(LIBFT_DIR) -o $@

$(LIBFT_DIR):
	@make -C libft

all: $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean

re: fclean all