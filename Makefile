################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        := $(shell find ./src -iname "*.c") 

OBJS        := $(SRCS:.c=.o)

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		:= rm -f

UNAME		:=	$(shell uname)

all:	script	play	${NAME}

script:
	@ bash banner.sh

ifeq ($(UNAME), Darwin)
play:
	@ afplay DAMAGE.wav &
endif

ifeq ($(UNAME), Linux)
play:
	@ aplay DAMAGE.wav &
endif

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@ echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			@ $(MAKE) -C libft/
			@ cp ./libft/libft.a .
			$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) libft.a -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@ afplay complete.wav &
			@ echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@ echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			@ $(MAKE) -C libft/
			@ cp ./libft/libft.a .
			$(CC) $(FLAGS) -g3 -o $(NAME) $(OBJS) libft.a -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@ aplay complete.wav &
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ aplay destroy.wav
			@ ${RM} ${NAME} libft.a libmlx.a /mlx_linux/libmlx.a
			@ $(MAKE) -C mlx_linux clean
			@ $(MAKE) -C libft/ fclean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ afplay destroy.wav
			@ ${RM} ${NAME} libft.a libmlx.a /mlx/libmlx.a
			@ $(MAKE) -C libft/ fclean
			@ $(MAKE) -C mlx clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re
