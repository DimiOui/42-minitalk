# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 14:49:36 by dpaccagn          #+#    #+#              #
#    Updated: 2022/01/25 18:05:47 by dimioui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(addprefix srcs/, \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strdup.c \
				ft_atoi.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c\
				ft_printf.c\
				ft_strjoin_char.c\
				)

LST			=	$(addprefix srcs/, \
				ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				)

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= ${LST:.c=.o}

NAME		= libft.a

RM			= @rm -f

CC			= @cc

CFLAGS		= -Wall -Wextra -Werror -I includes -c

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcsv ${NAME} ${OBJS} > /dev/null

all:		${NAME}

bonus:		${OBJS} ${BONUS_OBJS}
			@ar rcsv ${NAME} ${OBJS} ${BONUS_OBJS} > /dev/null

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: bonus re clean fclean
