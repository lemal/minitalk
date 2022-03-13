NAME_CL	=		client
NAME_SRVR	=	server

SRCS_CL	=		main_cl.c
SRCS_SRVR	=	main_srvr.c
SRCS_COMMON	=	ft_printf_core_func.c printf_bits_more.c printf_bits.c atoi.c

OBJS_CL	=		${SRCS_CL:%.c=%.o}
OBJS_SRVR	=	${SRCS_SRVR:%.c=%.o}
OBJS_COMMON	=	${SRCS_COMMON:%.c=%.o}

CC	=			cc
RM	=			rm -f
C_FLAGS	=		-Wall -Wextra -Werror -fsanitize=address

%.o:	%.c Makefile
	${CC} ${C_FLAGS} ${SRCS_CL} ${SRCS_SRVR} ${SRCS_COMMON} -c

all:	${NAME_SRVR} ${NAME_CL}

${NAME_SRVR}:	${OBJS_SRVR}
	${CC} ${C_FLAGS} ${OBJS_SRVR} ${OBJS_COMMON} -o ${NAME_SRVR}

${NAME_CL}:	${OBJS_CL}
	${CC} ${C_FLAGS} ${OBJS_CL} ${OBJS_COMMON} -o ${NAME_CL}

clean:
	${RM} ${OBJS_SRVR} ${OBJS_CL} ${OBJS_COMMON}
fclean:	clean
	${RM} ${NAME_CL} ${NAME_SRVR}
re:	fclean	all

.PHONY:	all clean fclean re