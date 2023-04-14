LIBNAME = libftcontainers.a

CC = c++ -Wall -Wextra -Werror

BINARIES_DIR = bin
HEADERS_DIR = include
TEMPLATES_DIR = src
OBJS_DIR = objs

HEADERS = ft_map.hpp ft_set.hpp ft_stack.hpp ft_vector.hpp
TEMPLATES = ft_map.tpp ft_set.tpp ft_stack.tpp ft_vector.tpp

OBJECTS = $(addprefix $(OBJS_DIR)/,$(HEADERS:.hpp=.o))

all: mkdirs $(LIBNAME)

mkdirs:
	@mkdir -p $(BINARIES_DIR)
	@mkdir -p $(OBJS_DIR)

$(LIBNAME): $(OBJECTS)
	ar rcs $(LIBNAME) $(OBJECTS)

$(OBJS_DIR)/%.o: $(HEADERS_DIR)/%.hpp
	$(CC) $(CFLAGS) -c -I $(TEMPLATES_DIR) $< -o $@

run: all
	$(CC) $(CFLAGS) main.cpp -I $(HEADERS_DIR) -I $(TEMPLATES_DIR) -o $(BINARIES_DIR)/main.out
	./$(BINARIES_DIR)/main.out

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
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re run valgrind