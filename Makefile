# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlely <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 11:41:33 by hlely             #+#    #+#              #
#    Updated: 2017/12/09 15:25:45 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wformat -Wextra -Werror 
SRCS = main.c\
	   ft_basic.c\
	   ft_check.c\
	   ft_cd.c\
	   ft_echo.c\
	   ft_env.c\
	   ft_touppercase.c
LIBFT = ./libft/
NAME = minishell
OBJ = $(addprefix src/,$(SRCS:.c=.o))
MAKEFLAGS = s

all:  $(NAME)

$(NAME): $(OBJ)
	@echo Checking libft ...
	@$(MAKE) -C $(LIBFT) MAKEFLAGS=s
	@echo Compiling minishell ...
	@cd src/; $(CC) -c $(FLAGS) $(SRCS)
	@$(CC) -Incurses  $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	@echo "\033[22;32mCompilation minishell OK\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo Cleaned object files

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaned $(NAME)"

re : fclean all
