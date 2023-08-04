# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2023/08/04 02:58:09 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	  =  ./src/action.c ./src/atoi.c ./src/error.c ./src/mutex.c ./src/threads.c ./src/utils.c ./src/verif.c
NAME	  = philo.a
OBJS	  =  ${SRCS:.c=.o}
EXE       = philo

all : ${NAME}
.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}


${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}
		gcc -Wall -Werror -Wextra main.c ${NAME} -lpthread -o ${EXE}

clean :
		rm -f ${OBJS}
		rm -f ${NAME}

fclean : clean
		rm -f ${EXE}

re : fclean all
