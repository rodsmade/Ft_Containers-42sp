NAME = containers.out

CC = c++ -Wall -Wextra -Werror
INCLUDES = -I./headers -I./map -I./set -I./stack -I./vector

OBJDIR = ./objs

SOURCES = ft_map.tpp ft_set.tpp ft_stack.tpp ft_vector.tpp
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:.tpp=.o))

all: mkdirs $(NAME)

mkdirs:
	@mkdir -p $(OBJDIR)

$(NAME): main.cpp vector/ft_vector.hpp vector/ft_vector.tpp
	$(CC) $(CFLAGS) main.cpp $(INCLUDES) -o $(NAME)

run: all
	./$(NAME)

valgrind: all
	valgrind --tool=memcheck \
		--show-leak-kinds=all \
		--leak-check=full \
		--track-origins=yes \
		--show-reachable=yes \
		--undef-value-errors=yes \
		--error-exitcode=42 \
		--quiet \
		./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind