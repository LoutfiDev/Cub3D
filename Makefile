# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 14:56:50 by yloutfi           #+#    #+#              #
#    Updated: 2023/08/21 12:48:22 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -I /nfs/homes/yloutfi/minilibx-linux -I ./libft \
	-Wall -Wextra -Werror -fsanitize=address -g3
DFLAGS = -Llibft -lft 
MLX = -L /nfs/homes/yloutfi/minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
CC = cc

SRCS = main.c  draw.c events.c init.c
		
PARSE_SRC = ./parse/parse.c	./parse/map_parsing.c ./parse/map_parsing2.c \
		./parse/param_parsing.c ./parse/utils.c ./parse/global_free.c

	
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