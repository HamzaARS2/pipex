CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c files_manager.c

LIBFT_DIR = libft/libft.a

NAME = pipex


$(NAME): $(SRCS) $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR) -o $@

$(LIBFT_DIR):
	@make -C libft

all: $(NAME)

clean:
	@make -C libft clean