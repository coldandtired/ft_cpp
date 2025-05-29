# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 12:28:44 by lwillis           #+#    #+#              #
#    Updated: 2025/03/13 14:54:59 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./ex00
	@make -C ./ex01
	@make -C ./ex02
	@make -C ./ex03

clean:
	@make clean -C ./ex00
	@make clean -C ./ex01
	@make clean -C ./ex02
	@make clean -C ./ex03
	
fclean:
	@make fclean -C ./ex00
	@make fclean -C ./ex01
	@make fclean -C ./ex02
	@make fclean -C ./ex03

re: clean all

.PHONY: all clean fclean re
