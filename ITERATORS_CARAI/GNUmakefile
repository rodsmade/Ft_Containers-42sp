NAME = map_test.out

SOURCE = main.cpp

all: $(NAME)
	./$(NAME)

vaval: $(NAME)
	valgrind --quiet --tool=memcheck --show-leak-kinds=all --leak-check=full --track-origins=yes --show-reachable=yes --undef-value-errors=yes ./$(NAME)

$(NAME): $(SOURCE) ft_map.hpp ft_map.tpp
	clear && c++ -Wall -Wextra -Werror -std=c++98 -g $(SOURCE) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all vaval fclean re
