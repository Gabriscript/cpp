
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++11
SRC = main.cpp ScalarConverter.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
NAME = convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re