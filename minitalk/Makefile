SRCS 		= client.c client_func.c add_func.c server.c server_func.c
 
OBJSCLIENT	= client.o client_func.o add_func.o

OBJSSERVER	= server.o server_func.o add_func.o

NAME		= minitalk

SERVER		= server

CLIENT		= client

HEAD		= ./minitalk.h

SRCS_BONUS		= client_bonus.c client_func_bonus.c add_func_bonus.c server_bonus.c server_func_bonus.c
 
OBJSCLIENT_BONUS	= client_bonus.o client_func_bonus.o add_func_bonus.o

OBJSSERVER_BONUS	= server_bonus.o server_func_bonus.o add_func_bonus.o

NAME_BONUS		= minitalk_bonus

SERVER_BONUS		= server_bonus

CLIENT_BONUS		= client_bonus

HEAD_BONUS		= ./minitalk_bonus.h

CC			= gcc

RM			= rm -f

INC			= ./

CFLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

%.o:		%.c ${HEAD}
			${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

%bonus.o:		%bonus.c ${HEAD_BONUS}
			${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

all:		${NAME}

${CLIENT}:	${OBJSCLIENT}
			${CC} ${CFLAGS} ${OBJSCLIENT} -o ${CLIENT}

${SERVER}:	${OBJSSERVER} 
			${CC} ${CFLAGS} ${OBJSSERVER} -o ${SERVER}

${NAME}:	${CLIENT} ${SERVER}

clean:		
			${RM} ${OBJSSERVER} ${OBJSCLIENT}

fclean:		clean
			${RM} ${CLIENT} ${SERVER}

re:			fclean all

bonus:		${HEAD_BONUS} ${NAME_BONUS} ./minitalk_bonus.h

${CLIENT_BONUS}:	${OBJSCLIENT_BONUS}
			${CC} ${CFLAGS} ${OBJSCLIENT_BONUS} -o ${CLIENT_BONUS}

${SERVER_BONUS}:	${OBJSSERVER_BONUS} 
			${CC} ${CFLAGS} ${OBJSSERVER_BONUS} -o ${SERVER_BONUS}

${NAME_BONUS}:	${CLIENT_BONUS} ${SERVER_BONUS}

cleanbonus:		
			${RM} ${OBJSSERVER_BONUS} ${OBJSCLIENT_BONUS}

fcleanbonus:		cleanbonus
			${RM} ${CLIENT_BONUS} ${SERVER_BONUS}

rebonus:			fcleanbonus bonus

cleanall:		fclean fcleanbonus