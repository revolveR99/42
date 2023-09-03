NAME = so_long

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = so_long.c\

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):  $(OBJ)
	make all -C mlx_linux
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all
