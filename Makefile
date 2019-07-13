# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 13:27:24 by ftrujill          #+#    #+#              #
#    Updated: 2019/07/13 17:43:59 by ftrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes
LFT_DIR = libft

SRC_PATH = ./$(SRC_DIR)/
OBJ_PATH = ./$(OBJ_DIR)/
INC_PATH = ./$(INC_DIR)/
LFT_PATH = ./$(LFT_DIR)/

SRC_EXEC_NAME = push_swap.c checker.c
OBJ_EXEC_NAME = $(SRC_EXEC_NAME:.c=.o)
SRC_EXEC = $(addprefix $(SRC_PATH),$(SRC_EXEC_NAME))
OBJ_EXEC = $(addprefix $(OBJ_PATH),$(OBJ_EXEC_NAME))

SRC_NAME = aux_prt.c aux_functions.c basic_actions.c actions.c initialization.c sorting.c sorting_aux.c visualization.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = push_swap.h
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
LIB = $(addprefix $(LFT_PATH),$(LIB_NAME))

all: $(NAME1) $(NAME2) $(SRC) $(OBJ) $(SRC_EXEC) $(OBJ_EXEC) $(INC) $(LIB)

.PHONY : all re clean fclean

$(NAME1): $(OBJ_PATH) $(OBJ) $(OBJ_EXEC) $(LIB)
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) $(OBJ) $(OBJ_PATH)push_swap.o -L $(LFT_PATH) -lft -o $(NAME1)

$(NAME2): $(OBJ_PATH) $(OBJ) $(OBJ_EXEC) $(LIB)
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) $(OBJ) $(OBJ_PATH)checker.o -L $(LFT_PATH) -lft -o $(NAME2)

$(OBJ_PATH):
	@mkdir -p $(OBJ_DIR)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) -o $@ -c $<

$(LIB):
	@make -C $(LFT_PATH)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_EXEC)
	@mkdir -p $(OBJ_DIR)
	@rmdir $(OBJ_DIR)
	@make -C $(LFT_PATH) clean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C $(LFT_PATH) fclean

re: fclean all
