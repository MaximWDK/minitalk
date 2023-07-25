SRCS = \
	client.c \
	server.c

OBJS = ${SRCS:.c=.o}
NAME = client server
LIBC = ar rcs
CC = gcc
RM = rm -f
LIBFTDIR = libft
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: client server

client: client.o
	make -C $(LIBFTDIR)
	${CC} ${CFLAGS} -o client client.o libft/libft.a

server: server.o
	${CC} ${CFLAGS} -o server server.o libft/libft.a
	
clean:
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFTDIR}
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
