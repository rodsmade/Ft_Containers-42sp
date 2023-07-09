all: testinho.out
	./testinho.out

testinho.out: testinho.cpp
	clear && c++ -Wall -Wextra -Werror -std=c++98 -g testinho.cpp -o testinho.out

vaval: testinho.out
	valgrind --quiet --tool=memcheck --show-leak-kinds=all --leak-check=full --track-origins=yes --show-reachable=yes --undef-value-errors=yes ./testinho.out

fclean:
	rm testinho.out