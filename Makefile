NAME = push_swap
NAME_B = checker
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
SRCS = ft_atoi.c main_push_swap.c sort_em_all.c swap.c swap_utils.c
SRCS_BONUS = gnl_recusif.c main_checker.c ft_atoi.c sort_em_all.c swap.c swap_utils.c

CC = gcc
OBJ = ${SRCS:.c=.o}
OBJS = *.o
OBJ_B = ${SRCS_BONUS:.c=.o}
OBJS_B = *.o

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME)	: $(OBJ) 
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAME_B) : ${OBJ_B}
			$(CC) $(FLAGS) -o $(NAME_B) $(OBJ_B)
clean : 
		rm -rf $(NAME) $(NAME_B)

fclean : clean
		rm -rf $(OBJS)

re : fclean all

bonus : fclean ${NAME_B}
