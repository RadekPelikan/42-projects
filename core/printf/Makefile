OBJ_DIR		:= ./obj
SRC_DIR		:= ./src
DEBUG_DIR	:= ./debug
BUILD_DIR	:= ./build

FLAGS		:= -Wall -Wextra -Werror

CC			:= clang
LIBC		:= ar rcs
RM			:= rm -rf

NAME		:=	libftprintf.a
SO_NAME		:=	$(NAME:.a=.o)
DEBUG_BIN	:= $(DEBUG_DIR)/bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

DEBUG_SRCS := $(wildcard $(DEBUG_DIR)/*.c)
DEBUG_OBJS := $(DEBUG_SRCS:.c=.o)

AR_OBJ	:= $(BUILD_DIR)/$(NAME)
SO_OBJ	:= $(BUILD_DIR)/$(SO_NAME)

all: .MKDIR_BUILD $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(AR_OBJ) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c -o $@ $<

re:	fclean all

fclean: clean
	$(RM) $(AR_OBJ) $(DEBUG_BIN)

clean:
	$(RM) $(OBJS) $(SO_OBJ) $(DEBUG_OBJS)

debug: .DEBUG_FLAG $(SO_OBJ) $(DEBUG_OBJS)
	$(CC) -o $(DEBUG_BIN) $(SO_OBJ) $(DEBUG_OBJS)
	@./$(DEBUG_BIN)

so: .MKDIR_BUILD $(SO_OBJ) 

$(SO_OBJ):
	$(CC) $(FLAGS) -c -fPIC $(SRCS) -o $(SO_OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

diff:
	@git status
	@git --no-pager diff --stat

.MKDIR_BUILD:
	mkdir -p $(BUILD_DIR)

.DEBUG_FLAG:
	$(eval FLAGS += -g)

.PHONY: 	all clean fclean re debug so .MKDIR_BUILD .DEBUG_FLAG