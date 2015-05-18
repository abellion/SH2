/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 18:05:55 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 17:32:35 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		launcher_builtin(t_cmd *cmd, t_list **env)
{
	if (!cmd)
		return (0);
	if (ft_strequ(cmd->name, "env"))
		env_controller(cmd, env);
	if (ft_strequ(cmd->name, "setenv"))
		setenv_controller(cmd, env);
	if (ft_strequ(cmd->name, "unsetenv"))
		unsetenv_controller(cmd, env);
	if (ft_strequ(cmd->name, "cd"))
		cd_controller(cmd, env);
	if (ft_strequ(cmd->name, "exit"))
		exit_controller(cmd, env);
	return (1);
}

int		launcher_binary(t_cmd *cmd, char **env)
{
	pid_t	prog_id;

	if (!cmd)
		return (0);
	prog_id = fork();
	if (prog_id == 0)
		execve(cmd->path, cmd->args, env);
	else
		waitpid(prog_id, 0, WCONTINUED);
	return (1);
}

int		launcher_normal(t_cmd *cmd, t_list **env)
{
	char	**env_tab;

	if (!cmd)
		return (0);
	env_tab = (env && *env) ? lst_to_tab(*env) : NULL;
	if (builtin_is_available(BUILTINS, cmd->name))
		launcher_builtin(cmd, env);
	else
		launcher_binary(cmd, env_tab);
	ft_tabdel((void ***)&env_tab, ft_tabdel_str);
	return (1);
}
