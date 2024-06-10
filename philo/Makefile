# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:01:36 by muribe-l          #+#    #+#              #
#    Updated: 2024/06/10 16:48:20 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = main.c parse.c utils.c actions.c destroy.c init.c
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
