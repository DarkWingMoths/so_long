# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:57:07 by mgagnon           #+#    #+#              #
#    Updated: 2023/01/25 16:39:29 by mgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRCS = ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c \
		print_bits.c \
		ft_lstnew.c \
	  	ft_lstadd_front.c \
	  	ft_lstsize.c \
	  	ft_lstlast.c \
	  	ft_lstadd_back.c \
	  	ft_lstdelone.c \
	  	ft_lstclear.c \
	  	ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		nbr.c \
		utils.c \
		ft_printf.c \
		print_map.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_strjoin.c

OBJS = $(SRCS:.c=.o)


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
