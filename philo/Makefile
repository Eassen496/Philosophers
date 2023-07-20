# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2023/07/20 02:00:07 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	  =  ./src/action.c ./src/atoi.c ./src/error.c ./src/mutex.c ./src/threads.c ./src/utils.c ./src/verif.c
NAME	  = philo.a
OBJS	  =  ${SRCS:.c=.o}
EXE       = philo

all : ${NAME}
	gcc -Wall -Werror -Wextra main.c ${NAME} -lpthread -o ${EXE}

.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}


${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

clean :
		rm -f ${OBJS} exec
		rm -f ${EXE}

fclean : clean
		rm -f ${NAME}

re : fclean all
