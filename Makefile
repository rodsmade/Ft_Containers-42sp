STATIC_LIB = libftcontainers.a

CC = c++ -Wall -Wextra -Werror -std=c++98

BINARIES_DIR = bin
HEADERS_DIR = include
TEMPLATES_DIR = src
OBJS_DIR = objs
TESTS_DIR = tests

HEADERS = ft_map.hpp ft_set.hpp ft_stack.hpp ft_vector.hpp
TEMPLATES = ft_map.tpp ft_set.tpp ft_stack.tpp ft_vector.tpp

OBJECTS = $(addprefix $(OBJS_DIR)/,$(HEADERS:.hpp=.o))

TEST_FILES =	$(addprefix $(TESTS_DIR)/,	main.cpp \
											test_typedefs.cpp \
											test_vector_creation.cpp)

all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJS_DIR) $(OBJECTS)
	ar rcs $(STATIC_LIB) $(OBJECTS)

$(OBJS_DIR)/%.o: $(HEADERS_DIR)/%.hpp
	$(CC) $(CFLAGS) -c -I $(TEMPLATES_DIR) $< -o $@

$(OBJS_DIR):
	if [ ! -d "$(OBJS_DIR)" ]; then mkdir $(OBJS_DIR); fi

run: $(STATIC_LIB)
	if [ ! -d "$(BINARIES_DIR)" ]; then mkdir $(BINARIES_DIR); fi
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TEMPLATES_DIR) main.cpp -o $(BINARIES_DIR)/main.out
	./$(BINARIES_DIR)/main.out

tests: $(STATIC_LIB)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include -I $(TEMPLATES_DIR) $(TEST_FILES) -o $(BINARIES_DIR)/tests.out
	./$(BINARIES_DIR)/tests.out

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
	rm -f $(OBJECTS)
	rmdir --ignore-fail-on-non-empty $(OBJS_DIR)

fclean: clean
	rm -f $(BINARIES_DIR)/*
	rmdir --ignore-fail-on-non-empty $(BINARIES_DIR)
	rm -f $(STATIC_LIB)

re: fclean all

.PHONY: all clean fclean re run tests valgrind