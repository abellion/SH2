# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 21:03:07 by abellion          #+#    #+#              #
#    Updated: 2015/05/08 21:31:10 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =	gnl/get_next_line.c \
		\
		program_files/src/main.c \
		program_files/src/utilities/utilities_env.c \
		program_files/src/utilities/utilities_args_formater.c \
		program_files/src/utilities/utilities_args_manager.c \
		program_files/src/utilities/utilities_errors.c \
		program_files/src/utilities/utilities_lst.c \
		program_files/src/utilities/utilities_path_checker.c \
		program_files/src/utilities/utilities_path_formater.c \
		program_files/src/utilities/utilities_tab.c \
		\
		program_files/src/prompt/prompt_controller.c \
		\
		program_files/src/cmd/cmd_controller.c \
		program_files/src/cmd/cmd_update.c \
		program_files/src/cmd/cmd_make_splits.c \
		program_files/src/cmd/cmd_make_parts.c \
		program_files/src/cmd/cmd_utilities.c \
		program_files/src/cmd/cmd_lst_manager.c \
		program_files/src/cmd/cmd_get_redir.c \
		program_files/src/cmd/cmd_get_operator.c \
		program_files/src/cmd/cmd_get_args.c \
		program_files/src/cmd/cmd_get_name.c \
		program_files/src/cmd/cmd_get_path.c \
		\
		program_files/src/launcher/launcher_controller.c \
		program_files/src/launcher/launcher_errors_controller.c \
		program_files/src/launcher/launcher_errors_printer.c \
		program_files/src/launcher/launcher_normal.c \
		program_files/src/launcher/launcher_pipe.c \
		program_files/src/launcher/launcher_redirections.c \
		\
		program_files/src/builtins/env_controller.c \
		program_files/src/builtins/env_process.c \
		program_files/src/builtins/setenv_controller.c \
		program_files/src/builtins/setenv_process.c \
		program_files/src/builtins/unsetenv_controller.c \
		program_files/src/builtins/cd_controller.c \
		program_files/src/builtins/cd_process.c \
		program_files/src/builtins/cd_determine_path.c \
		program_files/src/builtins/cd_options.c \
		program_files/src/builtins/exit_controller.c \

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = ft_minishell2

C_G = $(shell echo "\033[0;32m")

C_END = $(shell echo "\033[0m")

all: $(SOFT_NAME)

$(SOFT_NAME): $(SRC_C)
	make -C libft/
	@echo "\n$(C_G)	==========	SOFTWARE COMPILATION	==========$(C_END)"
	gcc -g -Wall -Wextra -Werror -I libft/includes/ -c $(SRC_C)
	@echo "\n$(C_G)	==========	CREATING EXECUTBLE FILE	==========$(C_END)"
	gcc -o $(SOFT_NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	@echo "\n$(C_G)	==========	DELETING OBJECTS FILES	==========$(C_END)"
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	@echo "\n$(C_G)	==========	DELETING SOFT FILE		==========$(C_END)"
	rm -rf $(SOFT_NAME)

re: fclean all
