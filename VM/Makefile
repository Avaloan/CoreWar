# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 05:47:01 by gquerre           #+#    #+#              #
#    Updated: 2018/03/24 06:00:16 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar

SRC =	./environment/ft_Create_arena.c\
		./environment/ft_error.c\
		./environment/ft_finish.c\
		./environment/ft_how_many_pl\
		./environment/ft_init_players.c\
		./environment/ft_init_process.c\
		./treatment/ft_game_runner.c\
		./treatment/ft_play_turn.c\
		./treatment/ft_add_process.ct

FLAG =	-Wextra - Wall -Werror -03

SUPP =	./includes/corewar_vm.h ./SRC/libft/libft.a

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): SRC/libft.a $(OBJ)
	gcc -I $(SUPP) $(OBJ) -o $(NAME)

SRC/libft/libft.a:
	make fclean -C SRC/libft/
	make -C SRC/libft

clean:
	rm -f $(OBJ)
	rm -f SRC?libft/libft.a
	make clean -C SRC/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C SRC/libft/

re: fclean all

