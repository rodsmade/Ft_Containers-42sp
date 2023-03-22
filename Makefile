NAME = containers_test.out

CC = c++ -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.cpp FtVector.o
	$(CC) main.cpp FtVector.o -o $(NAME)

FtVector.o: FtVector.cpp FtVector.hpp
	$(CC) -c $< -o $@

clean:
	rm -rf FtVector.o

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean