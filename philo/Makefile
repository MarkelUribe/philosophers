# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:01:36 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/30 15:59:58 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = main.c
SDIR = ./src/
ODIR = ./src/obj

OBJECTS = $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -rf

$(ODIR)/%.o: $(SDIR)%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
