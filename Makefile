NAME = 

SRC_PATH = ./sources

SRC_NAME = 

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I./includes -I./libft/includes

MLXFLAGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: $(LIB) $(NAME)

$(LIB):
	make -C ./libft
	cp $(LIB) libft.a

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -fv $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -fv $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, test

norme:
	norminette $(SRC)

test: $(LIB) 
	rm -fv test
	$(CC) -o test $(NAME) main.c $(CPPFLAGS) $(MLXFLAGS) libft.a
	./test
