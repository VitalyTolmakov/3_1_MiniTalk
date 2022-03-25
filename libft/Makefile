# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 16:11:24 by fheidi            #+#    #+#              #
#    Updated: 2021/11/14 11:07:48 by fheidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RC = ar rc
RL = ranlib
CFLAGS = -Wall -Werror -Wextra -c
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
	  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_strtrim.c ft_strmapi.c ft_striteri.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADERS = libft.h
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(RC) $(NAME) $(OBJ)
	$(RL) $(NAME)

bonus: $(OBJ_BONUS)
	$(RC) $(NAME) $(OBJ_BONUS)
	$(RL) $(NAME)
	
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)


fclean: clean
	$(RM) $(NAME)

re: fclean all

n:
	norminette -R CheckForbiddenSourceHeader ./*.c

def:
	norminette -R CheckDefine ./*.h

.PHONY: all clean fclean re n def
