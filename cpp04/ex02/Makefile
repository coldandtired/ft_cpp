# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 11:39:09 by lwillis           #+#    #+#              #
#    Updated: 2025/03/12 14:19:35 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
