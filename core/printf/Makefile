OBJ_DIR		:= ./obj
SRC_DIRS	:= ./src ./libft
DEBUG_DIR	:= ./debug
BUILD_DIR	:= .

FLAGS		:= -Wall -Wextra -Werror

CC			:= clang
LIBC		:= ar rcs
RM			:= rm -rf

NAME		:=	libftprintf.a
SO_NAME		:=	$(NAME:.a=.so)
DEBUG_BIN	:= $(DEBUG_DIR)/bin

SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS := $(foreach srcdir,$(SRC_DIRS),$(patsubst $(srcdir)/%.c,$(OBJ_DIR)/$(notdir $(srcdir))/%.o,$(wildcard $(srcdir)/*.c)))

DEBUG_SRCS := $(wildcard $(DEBUG_DIR)/*.c)
DEBUG_OBJS := $(DEBUG_SRCS:.c=.o)

AR_OBJ	:= $(BUILD_DIR)/$(NAME)
SO_OBJ	:= $(BUILD_DIR)/$(SO_NAME)

all: .MKDIR_BUILD $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(AR_OBJ) $^

$(OBJ_DIR)/%.o: $(SRCS)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c -o $@ $<

re:	fclean all

fclean: clean
	$(RM) $(AR_OBJ) $(DEBUG_BIN)
	$(RM)  */*.a */*.so */*.o 

clean:
	$(RM) $(OBJS) $(SO_OBJ) $(DEBUG_OBJS)

run: buildDebug
	@$(DEBUG_BIN)

gdb: .DEBUG_FLAG buildDebug
	@gdb $(DEBUG_BIN)

buildDebug: .DEBUG_FLAG $(SO_OBJ) $(DEBUG_OBJS)
	$(CC) -o $(DEBUG_BIN) $(SO_OBJ) $(DEBUG_OBJS)
	

so: .MKDIR_BUILD $(SO_OBJ) 

$(SO_OBJ): $(SRCS)
	$(CC) $(FLAGS) -o $(SO_OBJ) -fPIC -shared $^

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

%.o: %.h
	$(CC) $(FLAGS) -c -o $@ $<

diff:
	@git status
	@git --no-pager diff --stat

.MKDIR_BUILD:
	mkdir -p $(BUILD_DIR)

.DEBUG_FLAG:
	$(eval FLAGS += -g)


.PHONY: 	