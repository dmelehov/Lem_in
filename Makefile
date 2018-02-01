# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 17:19:14 by dmelehov          #+#    #+#              #
#    Updated: 2018/01/31 21:05:42 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= lem-in
# ==================

# ===== Libft ======
LIBFT_DIR:= ./libft/
LIBFT:= $(LIBFT_DIR)libft.a
LIBFT_INC:= $(LIBFT_DIR)includes/
LIBFT_FLAGS:= -lft -L $(LIBFT_DIR)
# ==================

# ==== Standard ====
CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./src/
OBJ_DIR:= ./obj/
INC_DIR:= ./includes/
COD:= .cache_exists
HEADER_FLAGS:= -I $(INC_DIR) -I $(LIBFT_INC)
# ==================



# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ===== Auto =======
SRC:= $(wildcard $(SRC_DIR)*.c)
OBJ:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
# ==================

# ===== Rules ======
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -g $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@echo $(GREEN) "\n- $@ is ready :)" $(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)	

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
# ==================
