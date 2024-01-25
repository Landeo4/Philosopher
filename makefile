# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:13:36 by tpotilli          #+#    #+#              #
#    Updated: 2024/01/25 18:28:58 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Philosopher

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g3 -fsanitize=address
RM = rm -rf

SRCS	=	main.c \
			utils/ft_atol.c \
			utils/ft_int_overflow_checker.c \
			utils/ft_strlen.c \
			utils/ft_error_writer.c \
			utils/ft_get_time.c \
			utils/ft_usleep.c \
			utils/ft_strcmp.c \
			parsing/verify_arguments.c \
			src/initializer.c \
			src/end_program.c \
			src/actions.c \
			src/simulation.c \
			src/forks.c \

OBJS= $(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3 -g
.c.o:
		${CC} ${CFLAGS} -Iincludes -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re