C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS = -g -O0

NAME = easyfind

INCLUDES = easyfind.hpp
OPTIONAL = easyfind.tpp
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(CFLAGS) -o $(NAME) $(OBJS)

# Keep headers and such in the object rule so modifications in them triggers recompilation as well.
%.o: %.cpp $(INCLUDES) $(OPTIONAL)
	$(C) $(CFLAGS) -c $< -o $@

debug: $(OBJS)
	$(C) $(CFLAGS) $(DEBUG_FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug