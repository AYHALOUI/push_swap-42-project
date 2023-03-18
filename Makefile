# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 13:22:35 by ahaloui           #+#    #+#              #
#    Updated: 2023/03/11 17:26:04 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap

NAME_BONUS	=	checker

# mandatory files 
SRC			=	push_swap.c parsing_args.c lst_functions.c utils.c push_functions.c r_rotate_functions.c rotate_functions.c swap_functions.c\
				sort_three.c sort_five.c utils1.c sort_functions.c

# bonus files
SRC_BONUS	=	getnextline/get_next_line_utils.c getnextline/get_next_line.c checker_bonus.c parsing_args.c lst_functions.c utils.c push_functions.c r_rotate_functions.c rotate_functions.c swap_functions.c\
				sort_three.c sort_five.c utils1.c sort_functions.c

# bonus objects				
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

# mandatory objects
OBJ			=	$(SRC:.c=.o)

# libft library
LIBFT		=	libft/libft.a

# printf library
PRINTF		=   printf/libftprintf.a

# compiler
CC			=	cc

# remove
RM			=	rm -f

# flags
CFLAGS		=	-Wall -Wextra -Werror

# rule all
all:	$(NAME)

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

# rule for mandatory part
$(NAME): $(OBJ) 
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

# rule for clean
clean:
	@make clean -C libft
	@make clean -C printf
	@${RM} $(OBJ)

# rule for fclean
fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	@${RM} $(NAME) $(NAME_BONUS) ${OBJ} ${OBJ_BONUS}
	
# rule for bonus part
bonus:	 all $(NAME_BONUS)

# rule for bonus part
$(NAME_BONUS) :	$(OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(PRINTF)			

# rule for re
re:	fclean all