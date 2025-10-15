NAME	:= rush01
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP

SRC_DIR	:= srcs
INC_DIR	:= includes
OBJ_DIR	:= obj

SRCS	:= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS	:= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

-include $(DEPS)

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re:		fclean all

.PHONY: all clean fclean re