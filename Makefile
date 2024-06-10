# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 10:49:55 by lgosselk          #+#    #+#              #
#    Updated: 2023/10/30 14:33:28 by lgosselk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_print_char.c	\
			ft_print_string.c \
			ft_print_int.c \
			ft_print_unsigned.c \
			ft_print_hex.c \
			ft_print_pointer.c

OBJS	= ${SRCS:.c=.o}

HEAD	= ft_printf.h

NAME	= libftprintf.a

AUXNAME	= libft.a

AUXDIR	= ./libft

AR			= ar rc

RM			= rm -f

LIB			= ranlib

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
					${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

makelibft:
					@make -C ${AUXDIR}
					@cp ${AUXDIR}/${AUXNAME} .
					@mv ${AUXNAME} ${NAME}

${NAME}:	makelibft ${OBJS}
					${AR} ${NAME} ${OBJS}
					${LIB} ${NAME}

clean:
					${RM} ${OBJS}
					@cd ${AUXDIR} && make clean

fclean:		clean
					${RM} ${NAME}
					@cd ${AUXDIR} && make fclean

re:					fclean all

.PHONY:		all clean fclean re
