CC = c++ -Wall -Wextra -Werror -std=c++98

BINARIES_DIR = bin
HEADERS_DIR = include
TEMPLATES_DIR = src
TESTS_DIR = tests

HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_vector.hpp)
TEMPLATES = $(addprefix $(TEMPLATES_DIR)/,	ft_vector.tpp)

TEST_FILES =	$(addprefix $(TESTS_DIR)/,	main.cpp test_emptiness.cpp test_typedefs.cpp)

all: tests

tests: $(HEADERS) $(TEMPLATES) $(TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include -I $(TEMPLATES_DIR) $(TEST_FILES) -o tests.out
	./tests.out

valgrind: all
	valgrind --tool=memcheck \
		--show-leak-kinds=all \
		--leak-check=full \
		--track-origins=yes \
		--show-reachable=yes \
		--undef-value-errors=yes \
		--error-exitcode=42 \
		--quiet \
		./$(BINARIES_DIR)/main.out

clean:
# 	rm -f $(OBJECTS)
	if [ -d "$(OBJS_DIR)" ]; then rmdir --ignore-fail-on-non-empty $(OBJS_DIR); fi

fclean: clean
	rm -f $(BINARIES_DIR)/*
	if [ -d "$(BINARIES_DIR)" ]; then rmdir --ignore-fail-on-non-empty $(BINARIES_DIR); fi

re: fclean all

.PHONY: all clean fclean re tests valgrind