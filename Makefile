# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 13:27:24 by ftrujill          #+#    #+#              #
#    Updated: 2019/07/12 16:27:49 by ftrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

OBJ_DIR = objects

SRC_PATH = ./sources/
OBJ_PATH = ./$(OBJ_DIR)/
INC_PATH = ./includes/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = push_swap.h

SRC_NAME = aux_prt.c actions.c initialization.c visualization.c push_swap.c

all: $(NAME) $(SRC) $(OBJ) $(INC)

.PHONY : all re clean fclean

$(NAME): $(OBJ_PATH) $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) $(OBJ) -L $(LFT_PATH) -lft -o $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_DIR)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) -o $@ -c $< 

clean:
	@rm -rf $(OBJ)
	@mkdir -p $(OBJ_DIR)
	@rmdir $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
