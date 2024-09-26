# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpelikan <rpelikan@student.42prague.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 03:23:33 by rpelikan          #+#    #+#              #
#    Updated: 2024/09/26 00:34:17 by rpelikan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = $(filter-out ft_main.c, $(wildcard *.c))

INC = libft
OBJ = $(SRC:.c=.o)
NAME = get_next_line.a
DEBUG_NAME = main
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1
LIBC = ar rc
LIBFT = ./libft/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}
	${RM} ${DEBU_NAME}

fclean:	clean
	${RM} ${NAME}


re: fclean all

debug: .DEBUG_FLAG ${NAME}
	cc ${CFLAGS} -o ${DEBUG_NAME} ft_main.c ${NAME} -I ${INC}
	chmod +x ${DEBUG_NAME}

.DEBUG_FLAG:
	$(eval CFLAGS += -g)
