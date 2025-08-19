CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = ../src
SRC_TEST_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ../libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
# LDFLAGS =  -lreadline 
# INCLUDE = -Iinclude -I${LIBFT_DIR}/include
LDFLAGS = -L${LIBFT_DIR}/bin -lft -lcmocka -Wl,--wrap=readline 
INCLUDE = -I${SRC_DIR}/include -I${LIBFT_DIR}/include -Iinclude

SRCS = ${SRC_DIR}/minishell.c ${SRC_DIR}/get_imput.c
SRCS += ${SRC_TEST_DIR}/test_runner.c ${SRC_TEST_DIR}/get_imput_test.c

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
OBJS += ${SRCS:${SRC_TEST_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = test

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${OBJ_DIR}/%.o: ${SRC_TESTE_DIR}/%.c
	mkdir -p $(dir $@}
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT}

re: fclean all
