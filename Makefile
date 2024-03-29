# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 20:19:37 by rpapagna          #+#    #+#              #
#    Updated: 2019/11/18 13:20:43 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler
ARCHIVE = libft/libft.a
AUTHOR	= rpapagna

CFLAGS	= -Wall -Wextra -Werror
INCL	= -I includes/
OBJ_PATH= obj

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
MAG		=\033[0;35m
NC		=\033[0m

SRCS 	=main.c\
		set.c\
		play.c\
		phase_one.c\
		sort.c

OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

.PHONY: clean debug

all:	$(NAME)

clean:
		@make -C libft clean
		@rm -rf obj

fclean: clean
		@printf "[$(RED)$(NAME)$(NC)]\tRm binary\n" #PRINT
		@make -C libft fclean
		@rm -rf $(NAME).trace
		@rm -rf $(AUTHOR).$(NAME).dSYM
		@rm -rf $(AUTHOR).$(NAME)
		@rm -rf includes/$(NAME).h.gch

re: fclean all

$(NAME):$(ARCHIVE) $(OBJ)
		@gcc $(CFLAGS) $(OBJ_PATH)/*.o $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(GREEN)$(NAME)$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT

$(OBJ_PATH):
		@mkdir -p $@

$(OBJ_PATH)/%.o: srcs/%.c | $(OBJ_PATH)
		@gcc $(CFLAGS) $(INCL) -o $@ -c $<

$(ARCHIVE):
		@make -C libft

1mo:
		@gcc -Wall -Wextra -g $(addprefix srcs/,$(SRCS)) $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(GREEN)$(NAME)$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT

sanitize:
		@gcc -g -Wall -Wextra $(addprefix srcs/,$(SRCS)) $(ARCHIVE) -o $(AUTHOR).$(NAME)
		@printf "[$(YELLOW)debug$(NC)]\t[$(MAG)OK!$(NC)]\n" #PRINT
