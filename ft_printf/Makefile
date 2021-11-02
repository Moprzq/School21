SRCS		= ft_printf.c ft_printf_addfunc.c ft_printf_proc_type_handlers.c

NAME		= libftprintf.a

CC			= gcc

AR			= ar rc

RM			= rm -f

INC			= ./

HEAD		= ./ft_printf_header.h

CFLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

%.o:		%.c ${HEAD}
			${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re
