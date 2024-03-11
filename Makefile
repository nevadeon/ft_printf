NAME = libftprintf.a
SRC = ft_printf.c \
	ft_putnbr.c \
	ft_putothers.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
#-I libft

#MAKEFLAGS += -silent

all: $(NAME)

$(NAME): $(OBJ)
#	$(MAKE) -C libft
#	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
#	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
#	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re