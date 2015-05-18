/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:28:02 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 17:02:36 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define BUILTINS		"exit,cd,env,setenv,unsetenv"
# define ERR_NULLCMD	-1
# define ERR_REDIRECT	-2
# define ERR_NOTFOUND	-3
# define ERR_NORIGHTS	-4
# define ERR_NOFILE		-5
# define ERR_USAGE		-6
# define ERR_MANY		-7
# define ERR_FORMAT		-8
# define ERR_NOTDIR		-9

/*
** STRUCTS
*/
typedef struct	s_cmd
{
	char			*name;
	char			*path;
	char			**args;
	char			*redirection_type;
	char			*redirection_to;
	char			*operator_type;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_args
{
	char			*valid;
	char			*unvalid;
	char			**other;
}				t_args;

typedef struct	s_error
{
	int				number;
	char			*details;
}				t_error;

/*
** TYPEDEFS
*/
typedef void	(*t_printer)(t_error *error);

/*
** UTILITIES
*/
char			*env_get_from_tab(char *to_get, char **env);
char			*env_get_from_lst(char *to_get, t_list *env);

t_error			*errors_init(int number, char *details);
void			errors_delete(t_error **error);
void			errors_controller(t_error *error, t_printer printer_fun);

t_args			*args_init(void);
t_args			*args_put(t_cmd *cmd, char *available_options);
void			args_delete(t_args **args);
int				option_is(char *str);
int				option_is_valid(char *curent_option, char *available_options);
char			*option_valid_formater(char **args, char *available_options);
char			*option_unvalid_formater(char **args, char *available_options);
char			**option_other_formater(char **args, char *available_options);

char			**lst_to_tab(t_list *lst);
t_list			*tab_to_lst(char **tab);
void			disp_lst(t_list *lst);
t_cmd			*cmd_pop(t_cmd *lst, t_cmd *elem);

char			*path_checker_rights(char *path);
int				path_checker_isreg(char *path);
int				path_checker_isdir(char *path);
char			*path_clear(char *path);
char			*path_formater(char *path, char *cwd);

char			*tab_to_str(char **tab);
char			**tab_join(char **tab1, char **tab2);

/*
** PROMPT
*/
char			*prompt_controller(t_list *env, int get_input);
char			*prompt_get_cdir(char *path, char *user_name);
void			prompt_put_line(char *user_name, char *curent_d);
void			prompt_get_infos(t_list *env, char **user_name, char **path);

/*
** CMD
*/
t_cmd			*cmd_controller(char *input, t_list *env);
t_cmd			*cmd_process(char *input, t_list *env);
int				cmd_errors_controller(t_cmd *cmd);
void			cmd_errors_printer(t_error *error);

char			*cmd_is_redir(char *c, char *s);
int				cmd_is_operator(char c);
int				cmd_is_separator(char c, char s);
int				cmd_is_quot(char c);
int				cmd_find_quot(char c, char p);

t_cmd			*cmd_update(t_cmd *cmd, t_list *env);
char			*cmd_clear_exhaust(char *str);
char			*cmd_remove_exhaust(char *str);
char			*cmd_remove_quot(char *str);
char			*cmd_replace_special(char *str, t_list *env);

char			**cmd_make_splits(char *input);
int				cmd_nb_split(char *input);
char			*cmd_next_split(char *input);

char			**cmd_make_parts(char *input);
char			*cmd_next_part(char *input);
int				cmd_nb_parts(char *input);

t_cmd			*cmd_init(void);
void			cmd_delone(t_cmd **cmd);
void			cmd_delall(t_cmd **cmd);
void			cmd_put(t_cmd **cmd, char **parts, t_list *env);
t_cmd			*cmd_remove_empty(t_cmd *cmd);

char			*cmd_get_name(char **input);
char			*cmd_get_path(char **input, t_list *env);
char			**cmd_get_paths(t_list *env);
char			*cmd_path_search(char *cmd_name, char **paths);
char			*cmd_get_redir_type(char **input);
char			*cmd_get_redir_to(char **input);
char			*cmd_get_operator(char **input);
char			**cmd_get_args(char **input, t_cmd *cmd);
int				cmd_nb_args(char **input, t_cmd *cmd);
int				cmd_is_arg(char *str, t_cmd *cmd);

/*
** LAUNCHER
*/
int				launcher_controller(t_cmd *cmd, t_list **env);
int				is_pipe(t_cmd *cmd);
t_cmd			*move_to_next(t_cmd *cmd);
t_cmd			*launcher_errors_controller(t_cmd *cmd);
void			launcher_errors_printer(t_error *error);
int				builtin_is_available(char *builtins, char *cmd_name);
int				check_cmd(t_cmd *cmd, char **details);
int				check_redirection(t_cmd *cmd);
int				is_new_cmd(t_cmd *cmd);
int				launcher_normal(t_cmd *cmd, t_list **env);
int				launcher_builtin(t_cmd *cmd, t_list **env);
int				launcher_binary(t_cmd *cmd, char **env);
int				launcher_pipe(t_cmd *cmd, t_list **env);
int				run_pipe(t_cmd *cmd, t_list **env, int *fd);
int				redirection_controller(t_cmd *cmd);
int				redirection_right(t_cmd *cmd);
int				redirection_s_left(t_cmd *cmd);
int				redirection_d_left(t_cmd *cmd);

/*
** BUILTINS
*/
int				env_controller(t_cmd *cmd, t_list **env);
t_args			*env_errors_controller(t_cmd *cmd);
void			env_errors_printer(t_error *error);
void			env_process(t_args *args, t_list *env);
t_list			*env_set(char **args, t_list *env);
int				env_launcher(char **args, t_list *env);

int				exit_controller(t_cmd *cmd, t_list **env);
t_args			*exit_errors_controller(t_cmd *cmd);
void			exit_errors_printer(t_error *error);

int				unsetenv_controller(t_cmd *cmd, t_list **env);
t_list			*unsetenv_unset(char *name, t_list *env);

int				setenv_controller(t_cmd *cmd, t_list **env);
t_args			*setenv_errors_controller(t_cmd *cmd);
void			setenv_errors_printer(t_error *error);
t_list			*setenv_process(t_args *args, t_list *env);
t_list			*setenv_set(char *name, char *value, t_list *env);

int				cd_controller(t_cmd *cmd, t_list **env);
t_args			*cd_errors_controller(t_cmd *cmd);
void			cd_errors_printer(t_error *error);
void			cd_process(t_args *args, t_list *env);
char			*cd_determine_path(char *path, t_list *env);
char			*cd_option_p(char *path);

void			disp_tab(char **tab);
void			disp_cmd_lst(t_cmd *cmd);
void			disp_cmd_struct(t_cmd *cmd);
void			disp_args(t_args *args);

#endif
