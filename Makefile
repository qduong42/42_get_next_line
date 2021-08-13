CFLAGS = -Wall -Wextra -Werror
NAME = gnltest
SRCS =  main_2.c
OBJS = ${SRCS:.c=.o} #makes *.o from *.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o} 
RM = rm -f
CC = gcc

all: 
	gcc $(CFLAGS) -o $(NAME) main_2.c 
	./$(NAME)

clean:
	${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 
