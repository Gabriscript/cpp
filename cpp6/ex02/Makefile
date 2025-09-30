
CXX = c++
FLAGS = -Wall -Wextra -Werror -Wshadow 
SRC = main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)
NAME = identify
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