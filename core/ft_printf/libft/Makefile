SRCS		:= ft_putstr_fd.c ft_putendl_fd.c ft_atoi.c ft_strtrim.c ft_itoa.c ft_strnstr.c ft_memmove.c ft_putnbr_fd.c ft_memchr.c ft_strrchr.c ft_strchr.c ft_strdup.c ft_memcmp.c ft_substr.c ft_tolower.c ft_isalnum.c ft_strlen.c ft_isdigit.c ft_calloc.c ft_strjoin.c ft_isprint.c ft_strmapi.c ft_split.c ft_toupper.c ft_strlcat.c ft_bzero.c ft_isalpha.c ft_memset.c ft_striteri.c ft_isascii.c ft_strlcpy.c ft_memcpy.c ft_putchar_fd.c ft_strncmp.c ft_alloc_str.c ft_find.c ft_intlen.c ft_ltoa.c
SRC_BONUS	:= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
CC			:= clang
FLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

NAME	:=	libft.a

OBJS	:=	$(SRCS:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus:		${OBJS_BONUS}
			ar -rcs ${NAME} ${OBJS_BONUS}
	
.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I.

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re 