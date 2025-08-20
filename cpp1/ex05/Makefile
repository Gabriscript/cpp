# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 09:23:34 by ggargani          #+#    #+#              #
#    Updated: 2025/08/11 09:41:12 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
FLAGS = -Wall -Wextra -Werror 
SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Harl

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