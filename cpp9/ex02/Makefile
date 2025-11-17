CXX = c++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp  PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
NAME =  PmergeMe
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