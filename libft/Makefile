# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 16:33:57 by dmelehov          #+#    #+#              #
#    Updated: 2017/10/20 12:58:38 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= libft.a

FILES:= ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
	ft_isprint ft_itoa ft_memalloc ft_memccpy ft_memchr ft_memcmp \
	ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd \
	ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd \
	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup \
	ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen \
	ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ \
	ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub \
	ft_strtrim ft_tolower ft_toupper ft_lstnew ft_lstadd ft_lstiter \
	ft_lstdelone ft_lstdel ft_lstmap ft_realloc get_next_line

# ==================

# ==== Standard ====
CC:=gcc
CCHPATH:=cache/
SRCPATH:=src/
HDRPATH:=includes/
CFLAGS:=-Wall -Wextra -Werror -I $(HDRPATH)
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

# ====== Auto ======
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
 
CCHF:=.cache_exists
# MAKEFLAGS+=-j

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo ".\c"
	@$(CC) $(CFLAGS) -c $< -o $@

# %.c:
# 	@echo $(RED) "Missing file : $@" $(END)

$(CCHF):
	@mkdir -p $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

test:
	@echo "Files :" $(FILES)