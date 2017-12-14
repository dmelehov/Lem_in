# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 18:42:44 by dmelehov          #+#    #+#              #
#    Updated: 2017/10/20 20:19:31 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= ft_printf.a
FILES:= ft_printf ft_sprintf ft_conv_diu ft_conv_pox ft_conv_cs ft_formatparsing \
	ft_support_functions_1 ft_support_functions_2 ft_fillstruct ft_flagmanagement \
	ft_formatparsing_additional ft_conv_fen ft_conv_ga ft_parse_floats \
	ft_round_floats ft_modifyers_management ft_parse_colors ft_parse_floats2 ft_parse_a

# ----- Libft ------
LFTDIR:= ../libft/src/
LIBFILES:= ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memalloc \
    ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd \
    ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr \
    ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat \
    ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr \
    ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper ft_lstnew ft_lstadd \
    ft_lstiter ft_lstdelone ft_lstdel ft_lstmap ft_realloc get_next_line
# ==================

# ------------------
HDRPATH:=../libft/includes/
LIBCCH:=../libft/cache/
SRCPATH:=../libft/src/
COMPILER:= gcc
CFLAGS:= -Wall -Werror -Wextra -I $(HDRPATH)
LINKER:= ar rc
CCHPATH:= cache/
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addsuffix .c,$(FILES)) $(addprefix $(LFTDIR),$(addsuffix .c,$(LIBFILES)))
#OBJ:= ../libft/libft.a
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ2:=$(addprefix $(LIBCCH),$(addsuffix .o,$(LIBFILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
#@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@" $(RED)
	@$(LINKER) libft.a $(OBJ2)
	@$(LINKER) $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)
	@echo $(GREEN)"OK"$(EOC)

$(LIBCCH)%.o: $(LFTDIR)%.c
	@echo $(PURPLE) "\tCompiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

$(CCHPATH)%.o: %.c $(CCHF)
	@echo $(PURPLE) "\tCompiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir -p $(CCHPATH)
	@mkdir -p $(LIBCCH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH) $(LIBCCH)
	@rm -f $(CCHF)
#@make clean -C ../libft

fclean: clean
#@make fclean -C ../libft
	@rm -f $(NAME) libft.a

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) | grep -v Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme