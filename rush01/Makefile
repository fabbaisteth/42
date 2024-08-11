TOWER = ${shell gcc -Wall -Wextra -Werror -o rush01}

MY_SOURCES = print_solution.c \
			 input.c \
			 main.c

MY_HEADERS = print_solution.h \
			 input.h

MY_OBJECTS = ${MY_SOURCES:.c=.o}

DEPS = ${MY_HEADERS} Makefile

CC=gcc

CFLAGS = -Wall -Wextra -Werror

a_program: ${MY_OBJECTS}
	${CC} ${CFLAGS} -o rush01 ${MY_OBJECTS}
