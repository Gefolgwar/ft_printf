# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 01:34:02 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/19 10:34:44 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[31m
GRN     = \033[32m
YEL     = \033[33m
BLU     = \033[34m
MAG     = \033[35m
STD     = \033[0m

NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c

PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstlast.c ft_putnchar_fd.c ft_putnchar_fd.c	\
		ft_nbrlen.c ft_putstrn_fd.c ft_uitoa.c

SRC = ${PART1} ${PART2}

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I../inc/ -g

.o:.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}
		@echo "$(YEL)Libft: $(GRN)Mandatory$(YEL) part compiled and archived.$(STD)"

all:	${NAME}

bonus:	${OBJS} ${BONUS_OBJS}
		ar rc ${NAME} ${OBJS} ${BONUS_OBJS}
		@echo "$(YEL)Libft: $(GRN)Mandatory$(YEL) and $(MAG)Bonus$(YEL) part compiled and archived.$(STD)"

clean:
		${RM} ${OBJS} ${BONUS_OBJS}
		@echo "$(YEL)Libft: Object files cleaned.$(STD)"

fclean: clean
		${RM} ${NAME}
		@echo "Libft: Library removed."

re: fclean all

.PHONY: all clean fclean re