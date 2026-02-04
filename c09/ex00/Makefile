CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME = btc
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADER = easyfind.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all