NAME = push_swap
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRCS = ft_atoi.c main.c sort_em_all.c swap.c
CC = gcc
OBJ = ${SRCS:.c=.o}
OBJS = *.o

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME)	: $(OBJ) 
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean : 
		rm -rf $(NAME)

fclean : clean
		rm -rf $(OBJS)

re : fclean all

