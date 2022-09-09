# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 11:09:56 by mgagnon           #+#    #+#              #
#    Updated: 2022/09/09 12:09:40 by mgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
PRINTF = libftprintf.a
PRINTDIR = ft_printf/

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f

SCRS = so_long.c\

OBJS = $(SRCS:.c=.o)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(PRINTDIR)
	cp $(PRINTDIR)$(PRINTF) $(NAME)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTDIR) fclean

re: clean all
	$(MAKE) -C $(PRINTDIR) re

.PHONY: bonus all clean fclean re
