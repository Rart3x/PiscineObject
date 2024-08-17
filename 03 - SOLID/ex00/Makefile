NAME = exec

SRC_DIR = .
OBJ_DIR = .obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -MMD -MP -gdwarf-2

DIRDUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[0;32mCompilation successful.\033[0m\n"
	@$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(DIRDUP)
	@$(CC) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\033[0;32mCleanup successful.\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;32mFull cleanup successful.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re