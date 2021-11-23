NAME = push_swap
NAME_B = checker
FLAGS = -Wall -Wextra -g 
SRCS = 				srcs/main_file/main_push_swap.c		\
					srcs/utils.c						\
					srcs/init.c							\
					srcs/ft_lst.c						\
					srcs/sort.c							\
					srcs/fonction.c						\
					srcs/list_sort.c					\
					srcs/solver.c						\
					srcs/max_min_lst.c 					\
					srcs/pusher.c						\
					srcs/end_solver.c					\
					srcs/sort_algo.c					\
					srcs/pusher_utils.c
 
SRCS_BONUS = 		srcs/gnl_recusif.c		\
					srcs/main_file/main_checker_push_swap.c		\
					srcs/fonction.c						\
					srcs/list_sort.c					\
					srcs/utils.c						\
					srcs/init.c							\
					srcs/ft_lst.c						\
					srcs/max_min_lst.c					\
					srcs/pusher_utils.c

CC = gcc
OBJ = ${SRCS:.c=.o}
OBJS = *.o
OBJ_B = ${SRCS_BONUS:.c=.o}
OBJS_B = *.o

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I include/.

all : $(NAME)

$(NAME)	: $(OBJ) 
			$(CC) $(FLAGS) -I include/. -o $(NAME) $(OBJ)

$(NAME_B) : $(OBJ_B)
			$(CC) $(FLAGS) -I include/. -o $(NAME_B) $(OBJ_B)
clean : 
		rm -rf $(NAME) $(NAME_B)

fclean : clean
		rm -rf $(OBJS)

re : fclean all



bonus : ${NAME_B}

rebonus : flclean bonus
