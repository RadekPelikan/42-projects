OBJ_DIRS	:= ./obj
SRC_DIRS	:= ./src

FLAGS		:= -Wall -Wextra -Werror

CC			:= clang
LIBC		:= ar rcs
RM			:= rm -f

SRCS := $(foreach D, $(SRC_DIRS), $(wildcard $(D)/*.c))
OBJS := $(patsubst %.c, %.o, $(SRCS))

NAME	:=	libftprintf.a

# NAME, all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $@ $^

%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c -o $@ $<

re:	fclean all

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

run: all
	$(NAME)

.PHONY: 	all clean fclean re run