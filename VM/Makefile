# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 05:47:01 by gquerre           #+#    #+#              #
#    Updated: 2018/03/31 05:54:01 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar

SRC =	./main.c\
		./environment/ft_create_arena.c\
		./environment/ft_error.c\
		./environment/ft_finish.c\
		./environment/ft_how_many_pl.c\
		./environment/ft_init_players.c\
		./environment/ft_init_process.c\
		./treatment/ft_game_runner.c\
		./treatment/ft_play_turn.c\
		./treatment/ft_add_pc.c\
		./options/ft_options.c\
		./options/ft_apply_option.c\
		./options/ft_dump.c

V_SRC =	./visual/ft_end_visu.c\
		./visual/ft_fill_arena.c\
		./visual/ft_fill_info.c\
		./visual/ft_start_the_game_visu.c\
		./visual/ft_init_visual.c\
		./visual/ft_maj_visu.c

FLAG =	-g -Wextra -Wall -Werror -O3 -lncurses

SUPP =	./includes/corewar_vm.h ./SRC/libft/libft.a

OBJ =	$(SRC:.c=.o) $(V_SRC:.c=.o)

all: $(NAME)

$(NAME): SRC/libft/libft.a $(OBJ)
	gcc $(FLAG) -I $(SUPP) $(OBJ) -o $(NAME)

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

