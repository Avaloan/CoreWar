#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 22:22:27 by fdidelot          #+#    #+#              #
#    Updated: 2018/04/27 03:01:26 by snedir           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 		asm

SRCS = 		main.c \
			name_and_comment.c \
			tools.c \
			check.c \
			label.c \
			command.c \
			operator.c \
			check_param.c \
			lfork.c \
			zjump.c \
			fork.c \
			ld.c \
			create_coding_byte.c \

OBJS = 		$(SRCS:.c=.o)

SRCPATH = 	./srcs/

INCPATH =	./includes/

FLAGS = 	-Wall -Wextra -Werror

all : 		$(NAME)

$(NAME) :	$(addprefix $(SRCPATH), $(SRCS))
			@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) -I $(INCPATH)
			@make -C libft
			@printf "\033[0;34m> Compiling asm\033[0m"
			@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
			@printf "\033[0;32m OK\n\033[0m"
			@rm $(OBJS)

clean :
			@make -C libft clean
			@rm -rf $(OBJS)

fclean :	clean
			@make -C libft fclean
			@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
