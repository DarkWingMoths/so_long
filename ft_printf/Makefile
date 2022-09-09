# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:57:07 by mgagnon           #+#    #+#              #
#    Updated: 2022/08/08 10:12:39 by mgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBDIR = libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_printf.c\
	   utils.c\
	   nbr.c

OBJS = $(SRCS:.c=.o)


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)$(LIBFT) $(NAME)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: clean all
	$(MAKE) -C $(LIBDIR) re

.PHONY: bonus all clean fclean re
