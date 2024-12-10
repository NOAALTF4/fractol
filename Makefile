NAME = fractol

LIBFTPRINTF_DIR = includes/Libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

LIBFT_DIR = includes/Libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = includes/minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SRCS_DIR = srcs/
INC_DIR = includes/

SRCS = $(addprefix $(SRCS_DIR), main.c ft_fractol.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MINILIBX_DIR) -I$(LIBFTPRINTF_DIR)/includes -I$(LIBFT_DIR)/includes
LDFLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(MINILIBX) $(LDFLAGS) -o $(NAME)

$(LIBFTPRINTF):
	make --no-print-directory -C $(LIBFTPRINTF_DIR)

$(MINILIBX):
	make --no-print-directory -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFTPRINTF_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPRINTF_DIR) fclean
	make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
