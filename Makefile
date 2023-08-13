# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 14:56:50 by yloutfi           #+#    #+#              #
#    Updated: 2023/08/13 18:25:35 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = #-Wall -Wextra -Werror #-fsanitize=address -g
DFLAGS = -Llibft -lft
MLX = -lmlx -framework OpenGL -framework AppKit
MATH = -lm
CC = cc

SRCS = main.c ./parse/parse.c draw.c init.c events.c
	
OBJS = $(SRCS:.c=.o)

all : libft $(NAME)

libft:
	@$(MAKE) -C libft -s
	@$(MAKE) -C libft bonus -s
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(MLX) $(MATH) $(OBJS) -o $(NAME) 

clean :
	@$(MAKE) -C libft clean -s
	-rm -f $(OBJS)
		
fclean : clean
	@$(MAKE) -C libft fclean -s
	-rm -f $(NAME)

re : fclean	all

.PHONY: all libft clean fclean re