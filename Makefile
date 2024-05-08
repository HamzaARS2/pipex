CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN_FILES = pipex.c files_manager.c split_cmds.c commands_executor.c error_exit.c \
wait_childs.c split_path.c parse_str.c get_cmds_str.c set_paths.c handle_error.c \
dup_fd.c ft_strcmp.c
GNL_FILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MAIN_OBJS = $(MAIN_FILES:.c=.o)
GNL_OBJS = $(GNL_FILES:.c=.o)

LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/

LIBFT = $(LIBFT_DIR)libft.a
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

NAME = pipex

$(NAME): $(MAIN_OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC)  $(MAIN_OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

%.o: %.c pipex.h get_next_line/get_next_line.h
	$(CC)  -c  $< -o $@

all: $(NAME)

bonus: all

clean:
	rm -f $(MAIN_OBJS) $(GNL_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re: fclean all