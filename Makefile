##
## Makefile for 102chiffrement in /home/mathon_j/rendu/102chiffrement
## 
## Made by Jeremy Mathon
## Login   <mathon_j@epitech.net>
## 
## Started on  Mon Nov 25 15:37:45 2013 Jeremy Mathon
## Last update Sun Feb 16 21:43:36 2014 Jérémy MATHON
##

SRCS	=		./src/my_allum.c \
			./src/my_putchar.c \
			./src/my_getnbr.c \
			./src/my_envlen.c \
			./src/my_strlen.c \
			./src/my_envdup.c \
			./src/my_ia.c \
			./src/my_malloc.c \
			./src/my_player.c \
			./src/my_strncmp.c \
			./src/my_putstr.c

CC	=		gcc

NAME	=		allum1

CLFAGS +=		-Wextra -Wall
CFLAGS +=		-ansi -pedantic
CLFAGS +=		-I.

OBJS	=		$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -lcurses

clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
