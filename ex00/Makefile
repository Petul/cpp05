# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 21:07:26 by pleander          #+#    #+#              #
#    Updated: 2025/01/15 21:08:24 by pleander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Bureaucrat
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++11
SOURCES := main.cpp Bureaucrat.cpp

OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
		$(CXX) $(OBJECTS) -o $(NAME)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
		rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
		rm -f $(NAME)

.PHONY: re
re: fclean all
