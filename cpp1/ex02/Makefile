# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 09:09:01 by ggargani          #+#    #+#              #
#    Updated: 2025/08/11 09:41:29 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
FLAGS = -Wall -Wextra -Werror 
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = brain

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