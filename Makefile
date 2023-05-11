CC = c++ -Wall -Wextra -Werror -std=c++98 -g

TEST_BIN = tests.out

BINARIES_DIR = bin
HEADERS_DIR = include
TESTS_DIR = tests

HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_vector.hpp ft_vector.tpp)

TEST_FILES =	$(addprefix $(TESTS_DIR)/,	main.cpp \
											assert.cpp \
											test_access.cpp \
											test_allocator.cpp \
											test_assign.cpp \
											test_assignment_operator.cpp \
											test_back.cpp \
											test_cleanup.cpp \
											test_construction.cpp \
											test_data.cpp \
											test_emptiness.cpp \
											test_erase.cpp \
											test_front.cpp \
											test_insertion.cpp \
											test_iterators.cpp \
											test_max_size.cpp \
											test_operator_overloads.cpp \
											test_pop_back.cpp \
											test_push_back.cpp \
											test_reserve.cpp \
											test_resize.cpp \
											test_size_and_capacity.cpp \
											test_swap.cpp \
											test_typedefs.cpp \
											)

all: tests

build: $(HEADERS) $(TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include $(TEST_FILES) -o $(TEST_BIN)

run: build
	./$(TEST_BIN)

valgrind: build
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

.PHONY: all build clean fclean re run valgrind