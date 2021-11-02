SRCS		= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

NAME		= libft.a

CC			= gcc

AR			= ar rc

RM			= rm -f

INC			= -include libft.h

CFLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

SRCSBONUS 	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJSBONUS	= ${SRCSBONUS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

ifndef 		COMPILE_BONUS

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

else
${NAME}:	${OBJS} ${OBJSBONUS}
			${AR} ${NAME} ${OBJS} ${OBJSBONUS}
endif

all:		${NAME}

bonus:		
			${MAKE} COMPILE_BONUS=1 all

clean:		
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re, bonus
