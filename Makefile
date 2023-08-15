SRCS = client.c utils/ft_atoi.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
S_SRCS = server.c utils/ft_atoi.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
B_SRCS = client_bonus.c utils/ft_atoi.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
BS_SRCS = server_bonus.c utils/ft_atoi.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c

NAME = client
S_NAME = server
B_NAME = client_bonus
BS_NAME = server_bonus

OBJS = $(SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
BS_OBJS = $(BS_SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME) $(S_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(S_NAME): $(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -o $(S_NAME)

bonus: $(B_NAME) $(BS_NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS)

$(BS_NAME): $(BS_OBJS)
	$(CC) $(CFLAGS) -o $(BS_NAME) $(BS_OBJS)

clean:
	${RM} ${OBJS} ${S_OBJS} ${B_OBJS} ${BS_OBJS}

fclean: clean
	${RM} ${NAME} ${S_NAME} ${B_NAME} ${BS_NAME}

re: fclean all

.PHONY : all bonus clean fclean re
