CC=c++
FLAG=-Wall -Wextra -Werror -std=c++98
NAME=megaphone
SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)
RM=rm -f
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
fclean: clean	
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re