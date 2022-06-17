#INC=/usr/include


#INCLIB=$(INC)/../lib

NAME= minishell

BUILTINS =  cd.c \
			echo.c \
			m_env.c \
			pwd.c \
			unset.c \
			export.c \
			exit.c \

EXEC = 	redir.c \
		execute.c \
		child.c \

SRC = main.c \
	parse/parse.c \
	parse/token.c \
	env/env.c \
	utils/utils.c \
	utils/str_utils.c \
	utils/strs_utils.c \
	utils/appends.c \
	utils/token_utils.c \
	utils/parse_utils.c \
	other/garbage.c \
	$(addprefix execute/,$(EXEC))\
	$(addprefix builtin/,$(BUILTINS))\


OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	$(CC) ${OBJ} -I./ ./libft/libft.a  -lreadline -o $(NAME)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	@$(MAKE) -C libft fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

run: clean
	./minishell
