# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 13:44:31 by ahaloui           #+#    #+#              #
#    Updated: 2023/03/07 16:48:16 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   ft_isdigit.c ft_strlen.c ft_strncmp.c ft_strjoin.c ft_split.c ft_strdup.c ft_atoi.c
			
OBJECT = $(SRC:.c=.o)

CC = cc

ARCHIVE = ar -rc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) 
	@$(ARCHIVE) $(NAME) $(OBJECT)

%.o: %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	@$(RM) $(NAME)

re : fclean all