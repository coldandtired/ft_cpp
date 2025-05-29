# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 11:37:01 by lwillis           #+#    #+#              #
#    Updated: 2025/03/15 11:55:14 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRCS = main.cpp Bureaucrat.cpp

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
