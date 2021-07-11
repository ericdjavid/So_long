# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 16:12:18 by edjavid           #+#    #+#              #
#    Updated: 2020/12/15 12:02:44 by edjavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	./ft_atoi.c 		\
		./ft_bzero.c 		\
		./ft_isalnum.c 		\
		./ft_isalpha.c 		\
		./ft_isascii.c 		\
		./ft_isdigit.c 		\
		./ft_isprint.c 		\
  		./ft_strchr.c 		\
 		./ft_strcat.c       \
  		./ft_strlcpy.c 		\
 		./ft_strjoin.c 		\
		./ft_strlcat.c 		\
		./ft_strlen.c 		\
 		./ft_strncmp.c 		\
   		./ft_strnstr.c 		\
		./ft_strrchr.c 		\
  		./ft_substr.c 		\
		./ft_tolower.c 		\
		./ft_toupper.c 		\
		./ft_putchar_fd.c 	\
 		./ft_putendl_fd.c 	\
 		./ft_putstr_fd.c 	\
		./ft_putnbr_fd.c	\
		./ft_strtrim.c		\
		./ft_strcmp.c		\

OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
