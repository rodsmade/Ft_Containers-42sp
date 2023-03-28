NAME = containers.out

CC = c++ -Wall -Wextra -Werror

OBJDIR = ./objs

SOURCES = ft_map.cpp ft_set.cpp ft_stack.cpp ft_vector.cpp
OBJECTS = $(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))

all: mkdirs $(NAME)

mkdirs:
	@mkdir -p $(OBJDIR)

$(NAME): main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o:	%.cpp %.hpp
	$(CC) $(CFLAGS) $< -c -o $@

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind