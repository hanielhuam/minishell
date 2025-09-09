CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft -lreadline 
INCLUDE = -Iinclude -I${LIBFT_DIR}/include

SRCS = ${SRC_DIR}/minishell.c ${SRC_DIR}/get_input.c ${SRC_DIR}/get_env_list.c \
	   ${SRC_DIR}/show_error.c ${SRC_DIR}/safe_malloc.c \
	   ${SRC_DIR}/del_t_env.c ${SRC_DIR}/command_env.c ${SRC_DIR}/parser.c \
	   ${SRC_DIR}/destroy_shell.c ${SRC_DIR}/pre_process_input.c \
	   ${SRC_DIR}/validate_quote.c ${SRC_DIR}/executor.c \
	   ${SRC_DIR}/del_t_token.c ${SRC_DIR}/build_tree.c \
	   ${SRC_DIR}/get_tokens.c ${SRC_DIR}/get_meta_caracters.c \
	   ${SRC_DIR}/add_space.c ${SRC_DIR}/copy_and_paste.c \
	   ${SRC_DIR}/compare_with_oneof.c ${SRC_DIR}/modified_split.c \
	   ${SRC_DIR}/del_split.c

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = minishell

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

test: 
	make -C ${TEST_DIR}
	./${TEST_DIR}/test

${TEST_OBJ_DIR}/%.o: ${TEST_SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${TEST_INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR} clean && rm -rf ${TEST_OBJ_DIR}

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT} && rm -rf ${TEST}

re: fclean all
