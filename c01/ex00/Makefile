CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ = $(SRC:%.cpp=%.o)

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

