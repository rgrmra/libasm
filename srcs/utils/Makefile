# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 10:58:53 by rde-mour          #+#    #+#              #
#    Updated: 2026/03/21 15:57:18 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					= $(shell tput setaf 1)
GREEN				= $(shell tput setaf 2)
YELLOW				= $(shell tput setaf 3)
BLUE				= $(shell tput setaf 4)
MAGENTA				= $(shell tput setaf 5)
RESET				= $(shell tput sgr0)


NAME				= libft.a

SRCS				= ft_isalpha.s \
					  ft_isdigit.s \
					  ft_isalnum.s \
					  ft_isascii.s \
					  ft_isprint.s \
					  ft_strlen.s \
					  ft_memset.s \
					  ft_bzero.s \
					  ft_toupper.s \
					  ft_tolower.s \
					  ft_memchr.s \
					  ft_strchr.s \
					  ft_strrchr.s \
					  ft_strncmp.s \
					  ft_memchr.s \
					  ft_memcpy.s \
					  ft_memcmp.s \
					  ft_memmove.s \
					  ft_strdup.s \
					  ft_strlcpy.s \
					  ft_atoi.s \
					  ft_calloc.s \
					  ft_strnstr.s \
					  ft_putchar_fd.s \
					  ft_putstr_fd.s \
					  ft_putendl_fd.s \
					  ft_putnbr_fd.s \
#					  ft_strlcat.s \
#					  ft_substr.s \
#					  ft_strjoin.s \
#					  ft_strtrim.s \
#					  ft_itoa.s \
#					  ft_strmapi.s \
#					  ft_striteri.s \
#					  ft_split.s

#BONUS				= ft_lstnew_bonus.s \
#					  ft_lstadd_front_bonus.s \
#					  ft_lstsize_bonus.s \
#					  ft_lstlast_bonus.s \
#					  ft_lstadd_b.sk_bonus.s \
#					  ft_lstdelone_bonus.s \
#					  ft_ls.slear_bonus.s \
#					  ft_lstiter_bonus.s \
#					  ft_lstmap_bonus.s

INCLUDES			= ./ 

OBJS				= $(SRCS:%.s=%.o)
OBJSBONUS			= $(BONUS:%.s=%.o)

NASM 			= nasm
CFLAGS 				= -f elf64

ifdef 				WITH_BONUS
					OBJS += $(OBJSBONUS)
endif


all: 				$(NAME)

$(NAME): 			$(OBJS)
					@echo "$(GREEN)Compiling$(RESET) $@"
					@ar rc -s $(NAME) $(OBJS)

%.o: 				%.s
					@echo "$(GREEN)Compiling$(RESET) $<"
					@$(NASM) $(CFLAGS) $< -o $@

bonus:
					@make WITH_BONUS=TRUE --no-print-directory

clean:
					@echo "$(RED)Removing$(RESET) $(NAME) objects"
					@rm -f $(OBJS) $(OBJSBONUS)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -f $(NAME)

re:					fclean all

.PHONY:			 	all bonus clean fclean re
