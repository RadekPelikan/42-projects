# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 03:23:33 by rpelikan          #+#    #+#              #
#    Updated: 2024/09/19 19:06:05 by rpelikan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = $(filter-out ft_main.c, $(wildcard *.c))

INC = libft
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
DEBUG_NAME = main
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
LIBFT = ./libft/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}: ${OBJ}
	make -C ./libft
	cp ./libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJ}
	${RM} ${BONUS_O}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}


re: fclean all

debug: .DEBUG_FLAG ${NAME}
	cc ${CFLAGS} -o ${DEBUG_NAME} ft_main.c ${NAME} -I ${INC}
	chmod +x ${DEBUG_NAME}

.DEBUG_FLAG:
	$(eval CFLAGS += -g)
