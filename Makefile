NAME = push_swap
NAME_B = checker
FLAGS = -Wall -Wextra -g 
SRCS = main_push_swap.c utils.c init.c ft_lst.c sort.c fonction.c list_sort.c solver.c max_min_lst.c pusher.c end_solver.c sort_algo.c
 
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

$(NAME_B) : $(OBJ_B)
			$(CC) $(FLAGS) -o $(NAME_B) $(OBJ_B)
clean : 
		rm -rf $(NAME) $(NAME_B)

fclean : clean
		rm -rf $(OBJS)

re : fclean all



bonus : ${NAME_B}

rebonus : flclean bonus
