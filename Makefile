# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 17:19:14 by dmelehov          #+#    #+#              #
#    Updated: 2018/01/16 17:21:08 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= lem-in
# ==================

# ==== Standard ====
CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./
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

# ==================