# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2023/06/12 22:50:07 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	  =  ./arg_error_message.c ./utils.c
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
