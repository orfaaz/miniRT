NAME = miniRT

SRC = minirt.c \
	mrt_parser01.c \
	mrt_parser02.c \
	mrt_parser03.c \
	mrt_utils01.c	\
	mrt_error.c	\
	mrt_mlx.c

LIBDIR = ../libft
LIB = $(LIBDIR)/libft.a

MLXDIR = mlx_linux
MLX = $(MLXDIR)/libmlx.a

OBJDIR = objs
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -I $(LIBDIR)/ -I $(MLXDIR)/
MLXFLAGS = -L$(MLX_DIR) -lmlx -L/user/include -lXext -lX11 -lm -lbsd

$(NAME): $(LIB) $(MLX) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) $(MLX) $(LDFLAGS) $(MLXFLAGS)

all: $(LIB) $(OBJ) $(MLX) $(NAME)

$(OBJDIR)/%.o:%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

$(LIB):
	make -sC $(LIBDIR)

$(MLX):
	make -sC $(MLXDIR)

clean:
	rm -rf $(OBJDIR)
	make -sC $(LIBDIR) clean
	make -sC $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
