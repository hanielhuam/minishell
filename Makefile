CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft -lreadline 
INCLUDE = -Iinclude -I${LIBFT_DIR}/include
TEST_DIR = test
SRC_TEST_DIR = ${TEST_DIR}/src
OBJ_TEST_DIR = ${TEST_DIR}/obj
TEST_LDFLAGS = ${LDFLAGS} -lcmocka -Wl,--wrap=readline 
TEST_INCLUDE = ${INCLUDE} -I${TEST_DIR}/include

SRCS = ${SRC_DIR}/minishell.c ${SRC_DIR}/get_imput.c
OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

TEST_SRCS = ${SRC_TEST_DIR}/test_runner.c ${SRC_TEST_DIR}/get_imput_test.c
TEST_OBJS = ${TEST_SRCS:${SRC_TEST_DIR}/%.c=${OBJ_TEST_DIR}/%.o}

NAME = minishell

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

test: ${LIBFT} ${OBJS} ${TEST_OBJ}
	$(CC) ${CFLAGS} ${OBJS} ${TEST_OBJS} ${TEST_LDFLAGS} -o ${TEST_DIR}/test
	./${TEST_DIR}/test

${TEST_OBJ_DIR}/%.o: ${TEST_SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${TEST_INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR} clean && rm -rf ${TEST_OBJ_DIR}

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT} && rm -rf ${TEST}

re: fclean all
