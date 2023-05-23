# ANSI COLOURS
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
RESET := \033[0m

# ANSI TEXT FORMATTING
BOLD := \033[1m
UNDERLINE := \033[4m

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

TESTS = vector_tests.out stack_tests.out #map_tests.out set_tests.out

BINARIES_DIR = bin
HEADERS_DIR = include
TESTS_DIR = tests
TESTS_SUITE_DIR = suite
TESTS_VECTOR_DIR = vector
TESTS_STACK_DIR = stack

VECTOR_HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_vector.hpp ft_vector.tpp)
STACK_HEADERS = $(addprefix $(HEADERS_DIR)/,	ft_stack.hpp ft_stack.tpp)

TEST_PROPS = $(addprefix $(TESTS_DIR)/,	$(TESTS_SUITE_DIR)/assert.cpp \
									)

VECTOR_TEST_FILES =	$(addprefix $(TESTS_DIR)/,	$(TESTS_VECTOR_DIR)/main.cpp \
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

STACK_TEST_FILES =	$(addprefix $(TESTS_DIR)/,	$(TESTS_STACK_DIR)/main.cpp \
												$(TESTS_STACK_DIR)/test_assignment_operator.cpp \
												$(TESTS_STACK_DIR)/test_construction.cpp \
												$(TESTS_STACK_DIR)/test_operator_overloads.cpp \
												$(TESTS_STACK_DIR)/test_push_and_pop.cpp \
												$(TESTS_STACK_DIR)/test_top.cpp \
											)

build: $(TESTS)
	@echo "$(GREEN)$(BOLD)All tests$(RESET) built $(UNDERLINE)successfully$(RESET)! ✅"

test_all: build
	@for test in $(TESTS); do \
		echo "Running $$test"; \
		./$$test > /dev/null; \
		echo ""; \
	done

test_all_vg: build
	@for test in $(TESTS); do \
		echo "Running $$test with Valgrind"; \
		valgrind \
			--tool=memcheck \
			--show-leak-kinds=all \
			--leak-check=full \
			--track-origins=yes \
			--show-reachable=yes \
			--undef-value-errors=yes \
			--error-exitcode=42 \
			--quiet ./$$test > /dev/null; \
		echo ""; \
	done

test_vector: vector_tests.out
	@echo "Running $^"
	@./$^ > /dev/null
	@echo "(if nothing was printed, all is good !!)"

test_vector_vg: vector_tests.out
	@echo "Running $^ with Valgrind"
	@valgrind \
		--tool=memcheck \
		--show-leak-kinds=all \
		--leak-check=full \
		--track-origins=yes \
		--show-reachable=yes \
		--undef-value-errors=yes \
		--error-exitcode=42 \
		--quiet ./$^

vector_tests.out: $(VECTOR_HEADERS) $(VECTOR_TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include $(TEST_PROPS) $(VECTOR_TEST_FILES) -o $@

test_stack: stack_tests.out
	@echo "Running $^"
	@./$^

test_stack_vg: stack_tests.out
	@echo "Running $^ with Valgrind"
	@valgrind --tool=memcheck --show-leak-kinds=all --leak-check=full --track-origins=yes --show-reachable=yes --undef-value-errors=yes --error-exitcode=42 --quiet ./$^

stack_tests.out: $(STACK_HEADERS) $(STACK_TEST_FILES)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(TESTS_DIR)/include $(TEST_PROPS) $(STACK_TEST_FILES) -o $@

clean:
	rm -f $(TESTS)

re: fclean all

.PHONY: all build clean re run valgrind
