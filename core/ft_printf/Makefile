SRC_DIR		:= ./src
INC_DIRS	:= ./include
DEBUG_DIR	:= ./debug
BUILD_DIR	:= .

FLAGS		:= -Wall -Wextra -Werror 

CC			:= clang
LIBC		:= ar -rcs
RM			:= rm -rf

LIBFT		:= ./lib/libft.a
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

all: $(BUILD_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
# Doesnt work with multiple libs
	cp $(LIBFT) $(AR_OBJ)
	$(LIBC) $(AR_OBJ) $^
	
$(LIBFT):
	mkdir -p $(dir $(LIBFT))
	make bonus -C ./libft
	mv ./libft/libft.a $(dir $(LIBFT))

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

gdb: re buildDebug
	@gdb $(DEBUG_BIN)

buildDebug: .DEBUG_FLAG $(LIBFT) $(SO_OBJ) $(DEBUG_OBJS)
	$(CC) -o $(DEBUG_BIN) $(SO_OBJ) $(DEBUG_OBJS) -L$(dir $(LIBFT)) -lft

so: $(BUILD_DIR) $(SO_OBJ) 

$(SO_OBJ): $(SRCS)
	$(CC) $(CFLAGS) -o $(SO_OBJ) -fPIC -shared $^

diff:
	@git status
	@git --no-pager diff --stat

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.DEBUG_FLAG:
	$(eval CFLAGS += -g)


.PHONY:	all re fclean clean run gdb buildDebug so diff .MKDIR_BUILD .DEBUG_FLAG