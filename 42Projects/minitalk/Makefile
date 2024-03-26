CLIENT	= client
SERVER	= server

LIBFTPRINTF		= ft_printf/libftprintf.a
LIBFTPRINTF_DIR	= ft_printf

SRC_S	= server.c
SRC_C	= client.c

OBJ_S	= server.o
OBJ_C	= client.o

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(LIBFTPRINTF) $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S) minitalk.h
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "server ready. \n"

$(CLIENT) : $(OBJ_C) minitalk.h
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	@printf "client ready. \n"

$(LIBFTPRINTF) :
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

%.o : %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

clean :
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ rm -rf $(OBJ_S) $(OBJ_C)
	@ printf "object files removed.\n"

fclean :
	@ $(MAKE) fclean -C $(LIBFTPRINTF)
	@ rm -rf $(SERVER) $(CLIENT)
	@printf "client removed.\n"
	@printf "server removed.\n"

re : fclean all

.PHONY: all clean fclean re