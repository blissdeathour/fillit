# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+         #
#           1                                      +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 19:44:46 by fhilary           #+#    #+#              #
#    Updated: 2020/08/08 20:15:48 by fhilary          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is example. Customize it yourself.

SHELL=/bin/zsh

# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
GREENB = \033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #

CC = clang
CF = -Wall -Wextra -Werror -m64 -ggdb

NAME = fillit

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		$(LFT)/include/$(LFT).h
FILLIT_H =	include/libfi.h
# add your headers here

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
FILLIT_C	=	$(shell find src/ -name '*.c')
# add your source-files here

FILLIT_O	=	$(addprefix obj/, $(FILLIT_C:src/%.c=%.o))
# add your object-files here

# add YOUR_O here
ALLO = $(FILLIT_O)

.PHONY: dir $(LFT) clean fclean re all

all: $(NAME) # replace by your rule

# create obj directory
dir:
	@mkdir -p obj

# this is reference
$(NAME): $(LFT) $(FILLIT_O)
	@$(CC) $(CF) $(FILLIT_O) -L$(LFT) -lft -o $@
	@echo "\n> $(GREEN)fillit was created$(DEFAULT)"

# this is reference
obj/%.o: src/%.c $(FILLIT_H) $(LFT_H) | dir
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

$(LFT):
	@make all -C libft

# Do not change it. It should work properly.
clean:
	@make fclean -C $(LFT)
	@rm -f $(ALLO)
	@rm -rf obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

# Remove "@rm -f fillit" later
fclean: clean
	@rm -f $(NAME)
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
