NAME=minitalk
SERVER=server
CLIENT=client
FT_PRINTF_PATH=ft_printf
FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -l ftprintf -I $(FT_PRINTF_PATH)

CC=cc
CFLAGS=-Wall -Wextra -Werror

$(NAME): $(SERVER) $(CLIENT)

all: $(NAME)

$(SERVER): $(FT_PRINTF) $(SERVER).c
	$(CC) $(CFLAGS) $(SERVER).c -o $(SERVER) $(FT_PRINTF_LIB_FLAGS)

$(CLIENT): $(LIBFT) $(FT_PRINTF) $(CLIENT).c
	$(CC) $(CFLAGS) $(CLIENT).c -o $(CLIENT) $(FT_PRINTF_LIB_FLAGS) $(FT_LIBFT_LIB_FLAGS)

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_PATH)

clean:
	make -s -C $(FT_PRINTF_PATH) clean
	make -s -C $(LIBFT_PATH) clean

fclean:	clean
	$(RM) $(SERVER) $(CLIENT) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re