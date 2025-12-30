NAME = account
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = tests.cpp Account.cpp 
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.SECONDARY: $(OBJ)
.PHONY: clean fclean re