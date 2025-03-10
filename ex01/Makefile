C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS = -g -O0

NAME = Span

INCLUDES = Span.hpp
SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(CFLAGS) -o $(NAME) $(OBJS)

# Keep headers and such in the object rule so modifications in them triggers recompilation as well.
%.o: %.cpp $(OPTIONAL)
	$(C) $(CFLAGS) -c $< -o $@

debug: $(OBJS)
	$(C) $(CFLAGS) $(DEBUG_FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug