# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:16:03 by dmelehov          #+#    #+#              #
#    Updated: 2018/01/31 15:35:45 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= libft.a
# ==================

# ==== Standard ====
CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./src/*/src/
OBJ_DIR:= ./obj/
INC_DIR:= ./includes/
COD:= .cache_exists
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
SRC:= $(wildcard ./src/*/src/*.c)
OBJ:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
# ==================

# ===== Rules ======
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) "\n- $@ is ready to serve, my Lord" $(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(COD)
	@echo $(PURPLE)"#\c"$(END)
	@$(CC) $(CFLAGS) -c $< -o $@

$(COD):
	@mkdir -p $(OBJ_DIR)
	@touch $(COD)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(COD)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
# ==================