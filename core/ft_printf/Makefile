SRC_DIR		:= ./src
LIB_DIR		:= ./lib
INC_DIRS	:= ./include ./libft
DEBUG_DIR	:= ./debug
BUILD_DIR	:= .

FLAGS		:= -Wall -Wextra -Werror 

CC			:= clang
LIBC		:= ar -rcs
RM			:= rm -rf


NAME		:=	libftprintf.a
SO_NAME		:=	$(NAME:.a=.so)
DEBUG_BIN	:= $(DEBUG_DIR)/bin

INCFLAGS	:= $(foreach dir, $(INC_DIRS), -I$(dir))
CFLAGS		:= $(FLAGS) $(INCFLAGS)

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:.c=.o)

DEBUG_SRCS := $(wildcard $(DEBUG_DIR)/*.c)
DEBUG_OBJS := $(DEBUG_SRCS:.c=.o)

AR_OBJ	:= $(BUILD_DIR)/$(NAME)
SO_OBJ	:= $(BUILD_DIR)/$(SO_NAME)

all: .MKDIR_BUILD buildLibft $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(AR_OBJ) $^ 
	
buildLibft:
	mkdir -p $(LIB_DIR)
	make -C ./libft
	mv ./libft/libft.a $(LIB_DIR)/

%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< 

re:	fclean all

fclean: clean
	$(RM) $(AR_OBJ) $(DEBUG_BIN)
	$(RM)  */*.a */*.so */*.o 

clean:
	$(RM) $(OBJS) $(SO_OBJ) $(DEBUG_OBJS)

run: buildDebug
	@echo
	@$(DEBUG_BIN)

gdb: .DEBUG_FLAG buildDebug
	@gdb $(DEBUG_BIN)

buildDebug: .DEBUG_FLAG buildLibft $(SO_OBJ) $(DEBUG_OBJS)
	$(CC) -o $(DEBUG_BIN) $(SO_OBJ) $(DEBUG_OBJS) -L$(LIB_DIR) -lft

so: .MKDIR_BUILD $(SO_OBJ) 

$(SO_OBJ): $(SRCS)
	$(CC) $(CFLAGS) -o $(SO_OBJ) -fPIC -shared $^

diff:
	@git status
	@git --no-pager diff --stat

.MKDIR_BUILD:
	mkdir -p $(BUILD_DIR)

.DEBUG_FLAG:
	$(eval FLAGS += -g)


.PHONY:	all buildLibft re fclean clean run gdb buildDebug so diff .MKDIR_BUILD .DEBUG_FLAG