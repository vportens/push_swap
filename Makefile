FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all : 
	gcc *.c $(FLAGS)
