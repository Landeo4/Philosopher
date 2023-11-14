# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:13:36 by tpotilli          #+#    #+#              #
#    Updated: 2023/11/14 15:15:46 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Philo

OBJS_PATH	= objs/

SRCS	=	srcs/main.c\
			srcs/Parsing/parsing_manager.c\
			srcs/Utils/verif_numbers.c\
			srcs/Utils/ft_strlen.c\
			srcs/Utils/is_num.c\
			srcs/Utils/init_struct.c\
			srcs/Utils/ft_atoi.c\

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3 -Iincludes

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re

${OBJS_PATH}%.o: %.c
		@mkdir -p $(@D)
		${CC} ${CFLAGS} -c $< -o $@