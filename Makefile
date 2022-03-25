# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 14:27:47 by fheidi            #+#    #+#              #
#    Updated: 2022/03/06 15:08:01 by fheidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT	=	client
NAME_SERVER	=	server
SRC_CLIENT	=	client.c
SRC_SERVER	=	server.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

NAME_CLIENT_BONUS	=	client_bonus
NAME_SERVER_BONUS	=	server_bonus
SRC_CLIENT_BONUS	=	client_bonus.c
SRC_SERVER_BONUS	=	server_bonus.c
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS	=	$(SRC_SERVER_BONUS:.c=.o)

FLAGS		=	-Wall -Wextra -Werror
LIBS		=	-L./libft -lft
LIBFT 		=	libft.a

all: $(NAME_SERVER) $(NAME_CLIENT) $(LIBFT)
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS) $(LIBFT)

$(LIBFT):
	make -C libft

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@gcc -o $@ $< $(LIBS)
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@gcc -o $@ $< $(LIBS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	@gcc -o $@ $< $(LIBS)
$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	@gcc -o $@ $< $(LIBS)

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	make -C libft clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) libft/libft.a $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus
