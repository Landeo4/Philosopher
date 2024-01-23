# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:13:36 by tpotilli          #+#    #+#              #
#    Updated: 2024/01/23 18:41:40 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Philosopher

OBJS_PATH	= objs/

SRCS	=	srcs/main.c\
			srcs/Philo/actions_philo.c\
			srcs/Philo/routine.c\
			srcs/Parsing/parsing_manager.c\
			srcs/Utils/verif_numbers.c\
			srcs/Utils/ft_strlen.c\
			srcs/Utils/is_num.c\
			srcs/list/init_struct.c\
			srcs/Utils/ft_atoi.c\
			srcs/Utils/ft_atol.c\
			srcs/Utils/ft_bzero.c\
			srcs/Utils/ft_meme_set.c\
			srcs/Utils/ft_calloc.c\
			srcs/list/ft_create_cell.c\
			srcs/list/ft_free_list.c\
			srcs/list/ft_add_at.c\

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3 -Iincludes -pthread

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