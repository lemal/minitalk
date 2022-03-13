NAME_CL	=		client
NAME_SRVR	=	server

SRCS_CL	=		main_cl.c
SRCS_SRVR	=	main_srvr.c

HDRS	=		cl_header.h srvr_header.h

OBJS_CL	=		${SRCS_CL:%.c=%.o}
OBJS_SRVR	=	${SRCS_CL:%.c=%.o}

CC	=			cc
RM	=			rm -f
C_FLAGS	=		-Wall -Wextra -Werror -fsanitize=address

%.o:	%.c Makefile ${HDRS}
	${CC} ${C_FLAGS} ${SRCS_CL} ${SRCS_SRVR} -c

all:	${NAME_SRVR} ${NAME_CL}

${NAME_SRVR}:	${OBJS_SRVR}
	${CC} ${C_FLAGS} ${OBJS_SRVR} -o ${NAME_SRVR}

${NAME_CL}:	${OBJS_CL}
	${CC} ${C_FLAGS} ${OBJS_CL} -o ${NAME_CL}

clean:
	${RM} ${OBJS_SRVR} ${OBJS_CL}
fclean:	clean
	${RM} ${NAME_CL} ${NAME_SRVR}
re:	fclean	all

.PHONY:	all clean fclean re