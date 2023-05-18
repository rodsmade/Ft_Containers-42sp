CC = c++ -Wall -Wextra -Werror -std=c++98 -g

TEST_BIN = tests.out

BINARIES_DIR = bin
HEADERS_DIR = include
TESTS_DIR = tests
TESTS_VECTOR_DIR = vector

HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_vector.hpp ft_vector.tpp)

TEST_FILES =	$(addprefix $(TESTS_DIR)/,	main.cpp \
											suite/assert.cpp \
											$(TESTS_VECTOR_DIR)/test_access.cpp \
											$(TESTS_VECTOR_DIR)/test_allocator.cpp \
											$(TESTS_VECTOR_DIR)/test_assign.cpp \
											$(TESTS_VECTOR_DIR)/test_assignment_operator.cpp \
											$(TESTS_VECTOR_DIR)/test_back.cpp \
											$(TESTS_VECTOR_DIR)/test_cleanup.cpp \
											$(TESTS_VECTOR_DIR)/test_construction.cpp \
											$(TESTS_VECTOR_DIR)/test_data.cpp \
											$(TESTS_VECTOR_DIR)/test_emptiness.cpp \
											$(TESTS_VECTOR_DIR)/test_erase.cpp \
											$(TESTS_VECTOR_DIR)/test_front.cpp \
											$(TESTS_VECTOR_DIR)/test_insertion.cpp \
											$(TESTS_VECTOR_DIR)/test_iterators.cpp \
											$(TESTS_VECTOR_DIR)/test_max_size.cpp \
											$(TESTS_VECTOR_DIR)/test_operator_overloads.cpp \
											$(TESTS_VECTOR_DIR)/test_pop_back.cpp \
											$(TESTS_VECTOR_DIR)/test_push_back.cpp \
											$(TESTS_VECTOR_DIR)/test_reserve.cpp \
											$(TESTS_VECTOR_DIR)/test_resize.cpp \
											$(TESTS_VECTOR_DIR)/test_size_and_capacity.cpp \
											$(TESTS_VECTOR_DIR)/test_swap.cpp \
											$(TESTS_VECTOR_DIR)/test_typedefs.cpp \
											)

all: $(TEST_BIN)

$(TEST_BIN): $(HEADERS) $(TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include $(TEST_FILES) -o $(TEST_BIN)

build: $(TEST_BIN)

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
	rm -f $(TEST_BIN)
#	if [ -d "$(BINARIES_DIR)" ]; then rmdir --ignore-fail-on-non-empty $(BINARIES_DIR); fi

re: fclean all

.PHONY: all build clean fclean re run valgrind