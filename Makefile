# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 12:19:31 by amaitre           #+#    #+#              #
#    Updated: 2016/05/17 14:42:04 by amaitre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRC			=	src/prompt.c
SRC			+=	src/main.c
SRC			+=	src/push_swap.c
SRC			+=	src/game.c
SRC			+=	src/solve.c
SRC			+=	src/littlebutterfly.c
SRC			+=	src/chagasseenflame.c
SRC			+=	src/cmd.c
SRC			+=	src/list.c
SRC			+=	src/clev_rot.c

SRCO		=	$(SRC:.c=.o)
HEADERSLIB	=	libftprintf/includes
HEADERS		=	includes
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mPushSwap:\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADERSLIB) -I $(HEADERS)

$(NAME): $(SRCO)
	@make -C libftprintf/
	@$(CC)  $(CFLAGS) -o $@ $^ libftprintf/libftprintf.a
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m----- OK - PushSwap ------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [-bonus] [numbers...]\033[0m"
	@echo "\033[32m      -bonus launch bonus mode\033[0m"

clean:
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C libftprintf/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C libftprintf/
	@rm -f $(NAME)

.PHONY: re clean fclean all
