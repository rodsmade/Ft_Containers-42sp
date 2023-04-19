CC = c++ -Wall -Wextra -Werror -std=c++98

TEST_BIN = tests.out

BINARIES_DIR = bin
HEADERS_DIR = include
TESTS_DIR = tests

HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_vector.hpp ft_vector.tpp)

TEST_FILES =	$(addprefix $(TESTS_DIR)/,	main.cpp \
											test_cleanup.cpp \
											test_emptiness.cpp \
											test_typedefs.cpp \
											test_vector_creation.cpp)

all: tests

tests: $(HEADERS) $(TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include $(TEST_FILES) -o $(TEST_BIN)
	./$(TEST_BIN)

valgrind: all
	valgrind --tool=memcheck \
		--show-leak-kinds=all \
		--leak-check=full \
		--track-origins=yes \
		--show-reachable=yes \
		--undef-value-errors=yes \
		--error-exitcode=42 \
		--quiet \
		./$(TEST_BIN)

clean:
# 	rm -f $(OBJECTS)
	if [ -d "$(OBJS_DIR)" ]; then rmdir --ignore-fail-on-non-empty $(OBJS_DIR); fi

fclean: clean
	rm -f $(BINARIES_DIR)/*
	if [ -d "$(BINARIES_DIR)" ]; then rmdir --ignore-fail-on-non-empty $(BINARIES_DIR); fi

re: fclean all

.PHONY: all clean fclean re tests valgrind