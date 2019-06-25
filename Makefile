# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 20:19:37 by rpapagna          #+#    #+#              #
#    Updated: 2019/06/24 18:44:36 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler
ARCHIVE = libft/libft.a
AUTHOR	= rpapagna

CFLAGS	= -Wall -Werror -Wextra
INCL	= -I includes/

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
MAG		=\033[0;35m
NC		=\033[0m

SRCS 	=main.c

.PHONY: clean debug

all:	$(NAME)

clean:
		@make -C libft clean

fclean:
		@printf "[$(RED)$(NAME)$(NC)]\t\tRm binary\n" #PRINT
		@make -C libft fclean
		@rm -rf $(AUTHOR).$(NAME).dSYM
		@rm -rf $(AUTHOR).$(NAME)
		@rm -rf includes/$(NAME).h.gch

re: fclean all

$(NAME):
		@make -C libft
		@gcc $(CFLAGS) $(addprefix srcs/,$(SRCS)) $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(GREEN)$(NAME)$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT

1mo:
		@gcc -Wall -Wextra $(addprefix srcs/,$(SRCS)) $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(GREEN)$(NAME)$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT

debug:
		@gcc -g -Wall -Wextra $(addprefix srcs/,$(SRCS)) $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(YELLOW)debug$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT