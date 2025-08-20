# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 09:36:07 by ggargani          #+#    #+#              #
#    Updated: 2025/08/11 09:40:59 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
FLAGS = -Wall -Wextra -Werror 
SRC = 	main.cpp Zombie.cpp newZombie.cpp	randomChump.cpp

OBJ = $(SRC:.cpp=.o)

NAME = BraiiiiiiinnnzzzZ

all: $(NAME)


$(NAME):$(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re