# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 07:31:18 by rde-mour          #+#    #+#              #
#    Updated: 2026/03/11 11:38:05 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					:= $(shell tput setaf 1)
GREEN				:= $(shell tput setaf 2)
YELLOW				:= $(shell tput setaf 3)
BLUE				:= $(shell tput setaf 4)
MAGENTA				:= $(shell tput setaf 5)
RESET				:= $(shell tput sgr0)


NAME				:= libasm.a

FILES				:= ft_strlen.s \
					   ft_strcpy.s \
					   ft_strcmp.s \
					   ft_write.s \
					   ft_read.s \
					   ft_strdup.s

FILES_BONUS			:= $(FILES:%.s=%%.s)

SRCSDIR				:= ./srcs
OBJSDIR 			:= ./objs

INCLUDES			:= includes
BONUS				:= bonus

SRCSDIR_BONUS		:= $(SRCSDIR)/$(BONUS)
OBJSDIR_BONUS		:= $(OBJSDIR)/$(BONUS)
INCLUDES_BONUS		:= $(INCLUDES)/$(BONUS)

SRCS				:= $(FILES:%.s=$(SRCSDIR)/%.s)
OBJS				:= $(FILES:%.s=$(OBJSDIR)/%.o)
OBJS_BONUS			:= $(FILES_BONUS:%.c=%.o)

MESSAGE				:= mandatory

NASM				:= nasm

NASMFLAGS			:= -f elf64


ifdef				WITH_BONUS
	SRCS			:= $(FILES_BONUS:%.s=$(SRCSDIR_BONUS)/%.s)
	OBJS			:= $(FILES_BONUS:%.s=$(OBJSDIR_BONUS)/%.o)
	INCLUDES		:= $(INCLUDES_BONUS)
	MESSAGE			:= bonus
endif


all:				$(NAME)

$(NAME): 			$(OBJS)
					@ar rcs $(NAME) $(OBJS)
					@echo "$(GREEN)Added to $(RESET)$(NAME)"
					@echo "$(BLUE)Compiled $(MESSAGE) successfully"

$(OBJSDIR)/%.o: 	$(SRCSDIR)/%.s
					@mkdir -p $(@D)
					@$(NASM) $(NASMFLAGS) $< -o $@
					@echo "$(GREEN)Compiled $(RESET)$(notdir $<)"

bonus:
					@make WITH_BONUS=TRUE --no-print-directory

clean:
					@echo "$(RED)Removing$(RESET) objects"
					@rm -rf $(OBJSDIR)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean bonus re
