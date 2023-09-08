NAME = cub3D
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
DFLAGS = -Llibft -lft 
MLX =  -lmlx -lXext -lX11 -lm -lz
CC = gcc-11

SRCS = main.c draw.c event.c exec_utils.c global_free.c init.c intersection.c \
	   intersect_utils.c render.c
		
PARSE_SRC = ./parse/parse.c	./parse/map_parsing.c ./parse/map_parsing2.c \
		./parse/param_parsing.c ./parse/utils.c

OBJS = $(SRCS:.c=.o)
PARSE_OBJS = $(PARSE_SRC:.c=.o)

all : libft $(NAME)

libft:
	@$(MAKE) -C libft -s
	@$(MAKE) -C libft bonus -s

$(NAME) : $(OBJS) $(PARSE_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PARSE_OBJS) $(MLX) $(DFLAGS) -o $(NAME)

clean :
	@$(MAKE) -C libft clean -s
	-rm -f $(OBJS) $(PARSE_OBJS)
		
fclean : clean
	@$(MAKE) -C libft fclean -s
	-rm -f $(NAME)

re : fclean	all

.PHONY: all libft clean fclean re
