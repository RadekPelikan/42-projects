CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRCDIR = ./sources
SOURCES = $(shell find $(SRCDIR) -name "*.c")
OBJECTS = $(SOURCES:.c=.o)

NAME = bsq

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJECTS)

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

