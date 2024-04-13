NAME = libftprintf.a

SRC = ft_printf.c\
ft_printf_utils.c\
ft_putchar_fd.c\
ft_putlbase_fd.c\
ft_putptr_fd.c\
ft_putstr_fd.c\
ft_putulbase_fd.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

main:
	$(CC) main/main.c $(NAME)

.PHONY: all clean fclean re main