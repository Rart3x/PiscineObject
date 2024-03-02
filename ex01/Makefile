NAME = Graph

SRC_DIR = srcs/srcs
OBJ_DIR = .obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

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