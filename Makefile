SRCS = \
	client.c \
	server.c

OBJS = ${SRCS:.c=.o}
NAME = client server
LIBC = ar rcs
CC = gcc
RM = rm -f
LIBFTDIR	= libft
PRINTFDIR	= printf
LIBFT		= ${LIBFTDIR}/libft.a
PRINTF		= ${PRINTFDIR}/libftprintf.a
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: client server

server: server.o
	make -C ${LIBFTDIR}
	make -C ${PRINTFDIR}
	${CC} ${CFLAGS} -o server server.o printf/libftprintf.a

client: client.o
	make -C $(LIBFTDIR)
	make -C ${PRINTFDIR}
	${CC} ${CFLAGS} -o client client.o printf/libftprintf.a libft/libft.a
clean:
	make clean -C ${LIBFTDIR}
	make clean -C ${PRINTFDIR}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFTDIR}
	make fclean -C ${PRINTFDIR}
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re client server
