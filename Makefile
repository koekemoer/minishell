# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 10:20:16 by lkoekemo          #+#    #+#              #
#    Updated: 2016/12/09 11:15:07 by lkoekemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Werror -Wextra -g

SRC = m_getline.c m_loop.c main.c m_env.c \
	  m_getenv.c m_cd.c m_echo.c m_fork.c \
	  m_args.c

SRCDIR = ./src/

SRCS = $(addprefix $(SRCDIR), $(SRC)) 

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) -o $(NAME) $(SRCS) -L libft/ -lft
	@rm -f $(OBJ)

all: $(NAME) 

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
