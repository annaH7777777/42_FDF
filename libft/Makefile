# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 17:33:07 by annharut          #+#    #+#              #
#    Updated: 2022/01/08 19:58:25 by annharut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c ft_split.c\


BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c  ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c  ft_lstmap.c 


OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

CC  = gcc -g
RM	= rm -f

CFLAGS = -Wall -Wextra -Werror 

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
				ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
		        ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

all: ${NAME}

clean: 
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean 
				${RM} ${NAME}

re:			  fclean all

.PHONY : all clean fclean re


