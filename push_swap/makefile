# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samy <samy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:51:56 by sde-smed          #+#    #+#              #
#    Updated: 2023/03/07 10:53:34 by samy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS	= 	src/push_swap.c\
			src/utils.c\
			src/sort.c

LIB		= -L ./libft -lft
LIBFT	= libft/
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
RM		= rm -rf

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -g $(OBJS) $(LIB) -o $(NAME) -I $(LIBFT)
	@printf "$(_SUCCESS) $(NAME) ready.\n"
	
	
clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJS)
	@printf "$(_INFO) objects removed.\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)
	@printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

.PHONY:			all clean fclean re