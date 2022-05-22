SRCS			=	ft_error.c ft_freestrarr.c ft_strarrdup.c ft_sortstrarr.c ft_strarrlen.c ft_strarrsize.c\
					ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strcomb.c\
					ft_strnstr.c ft_strlcat.c ft_strcat.c ft_strcmp.c ft_strncmp.c ft_tolower.c \
					ft_itoa.c  ft_atoi.c ft_itoa_u.c ft_atol.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c\
					ft_strichr.c ft_strrchr.c ft_memccpy.c ft_memchr.c \
					ft_isalpha.c  ft_bzero.c  ft_isalnum.c ft_isprint.c  ft_isascii.c ft_str_isnum.c\
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c  ft_memset.c  \
					ft_putstr_fd.c ft_strlcpy.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
					ft_abs.c ft_min.c ft_max.c ft_swap.c ft_sign.c\
					$(wildcard ft_printf/*.c)\

OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS  = 	${BONUS:.c=.o}

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

.PHONY:		all clean fclean bonus

.SILENT: $(NAME) 

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs $@ $^
bonus: 	
			gcc ${CFLAGS} -c ${BONUS} ${SRCS}  ;ar -rcs ${NAME} ${BONUS_OBJS} 

.c.o:
			gcc ${CFLAGS} -c $< -o  ${@:.c = .o}  

clean:
			rm -f ${OBJS} ./*o

fclean:		clean
			rm -f ${NAME}

re:			fclean all