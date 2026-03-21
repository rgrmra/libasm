# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 07:31:18 by rde-mour          #+#    #+#              #
#    Updated: 2026/03/21 08:38:08 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

# = COLORS =====================================================================

RED					:= $(shell tput setaf 1)
GREEN				:= $(shell tput setaf 2)
YELLOW				:= $(shell tput setaf 3)
BLUE				:= $(shell tput setaf 4)
MAGENTA				:= $(shell tput setaf 5)
RESET				:= $(shell tput sgr0)


# NAMES ========================================================================

NAME				:= libasm.a
NAME_TEST			:= libasm_test


# DIRECTORIES ==================================================================

SRCSDIR				:= srcs
BONUSDIR			:= $(SRCSDIR)/bonus
OBJSDIR				:= objs
TESTDIR				:= tests
TESTBONUSDIR 		:= $(TESTDIR)/bonus
INCDIR				:= includes


# FILES ========================================================================

FILES				:=	ft_strlen.s \
						ft_strcpy.s \
						ft_strcmp.s \
						ft_write.s \
						ft_read.s \
						ft_strdup.s

FILES_BONUS 		:= ft_atoi_base_bonus.s \
					   ft_list_push_front_bonus.s \
					   ft_list_size_bonus.s \
					   ft_list_sort_bonus.s \
					   ft_list_remove_if_bonus.s


# SOURCES ======================================================================

SOURCES				:= $(addprefix $(SRCSDIR)/, $(FILES))
OBJECTS				:= $(addprefix $(OBJSDIR)/, $(FILES:%.s=%.o))

SOURCES_BONUS		:= $(addprefix $(BONUSDIR)/, $(FILES_BONUS))
OBJECTS_BONUS		:= $(addprefix $(OBJSDIR)/bonus/, $(FILES_BONUS:%.s=%.o))

SOURCES_TEST 		:= $(TESTDIR)/main.c \
					   $(addprefix $(TESTDIR)/, $(FILES:%.s=%_test.c)) \
					   $(addprefix $(TESTBONUSDIR)/, $(FILES_BONUS:%.s=%_test.c)) 

OBJECTS_TEST		:= $(patsubst $(TESTDIR)/%.c,$(OBJSDIR)/tests/%.o,$(SOURCES_TEST))


# COMPILERS ====================================================================

NASM				:= nasm
NASMFLAGS			:= -f elf64

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -O3

AR					:= ar rcs


# RULES ========================================================================

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo "$(GREEN)Added to $(RESET)$(NAME)"
	@echo "$(BLUE)Compiled mandatory successfully$(RESET)"

bonus: $(OBJECTS_BONUS)
	@$(AR) $(NAME) $(OBJECTS_BONUS)
	@echo "$(GREEN)Added to $(RESET)$(NAME)"
	@echo "$(BLUE)Compiled bonus successfully$(RESET)"

test: all bonus $(OBJECTS_TEST)
	@$(CC) $(CFLAGS) $(OBJECTS_TEST) -I$(INCDIR) -L. -lasm -o $(NAME_TEST)
	@echo "$(GREEN)Added to $(RESET)$(NAME_TEST)"
	@echo "$(BLUE)Compiled tests successfully$(RESET)"


# COMPILE RULES ================================================================

$(OBJSDIR)/%.o: $(SRCSDIR)/%.s
	@mkdir -p $(@D)
	@$(NASM) $(NASMFLAGS) $< -o $@
	@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

$(OBJSDIR)/bonus/%.o: $(BONUSDIR)/%.s
	@mkdir -p $(@D)
	@$(NASM) $(NASMFLAGS) $< -o $@
	@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

$(OBJSDIR)/tests/%.o: $(TESTDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"


# CLEAN RULES =================================================================

clean:
	@echo "$(RED)Removing$(RESET) objects"
	@rm -rf $(OBJSDIR)

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)"
	@rm -f $(NAME)
	@echo "$(RED)Removing$(RESET) $(NAME_TEST)"
	@rm -f $(NAME_TEST)

re: fclean all

.PHONY: all bonus test clean fclean re
