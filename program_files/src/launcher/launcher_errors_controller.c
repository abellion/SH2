/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_errors_controller.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:46:53 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 15:05:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int			builtin_is_available(char *builtins, char *cmd_name)
{
	int		index;
	char	**parts;

	if (!builtins || !cmd_name)
		return (0);
	index = 0;
	parts = ft_strsplit(builtins, ',');
	while (parts && parts[index])
	{
		if (ft_strequ(parts[index], cmd_name))
		{
			ft_tabdel((void ***)&parts, ft_tabdel_str);
			return (1);
		}
		index++;
	}
	ft_tabdel((void ***)&parts, ft_tabdel_str);
	return (0);
}

int			check_redirection(t_cmd *cmd)
{
	char	redirection;
	char	*rights;

	if (!cmd)
		return (0);
	rights = path_checker_rights(cmd->redirection_to);
	redirection = (cmd->redirection_type) ? cmd->redirection_type[0] : 0;
	if (redirection && redirection == '>' && rights && !ft_strchr(rights, 'w'))
		return (ERR_NORIGHTS);
	else if (ft_strequ(cmd->redirection_type, "<") && !rights)
		return (ERR_NOFILE);
	else if (ft_strequ(cmd->redirection_type, "<") && !ft_strchr(rights, 'r'))
		return (ERR_NORIGHTS);
	ft_strdel(&rights);
	return (1);
}

int			check_cmd(t_cmd *cmd, char **details)
{
	char	*path;
	char	*rights;
	int		error;

	if (!cmd || !details)
		return (0);
	path = cmd->path;
	rights = path_checker_rights(path);
	if ((error = check_redirection(cmd)) < 0)
		return (*details = ft_strdup(cmd->redirection_to), error);
	if (builtin_is_available(BUILTINS, cmd->name))
		return (1);
	else if (ft_strchr(rights, 'x') && path_checker_isreg(path))
		return (1);
	else
	{
		*details = ft_strdup(cmd->name);
		if (cmd->name[0] != '.' && cmd->name[0] != '/')
			return (ERR_NOTFOUND);
		else if (!rights)
			return (ERR_NOFILE);
		else if (!ft_strchr(rights, 'x') || !path_checker_isreg(path))
			return (ERR_NORIGHTS);
	}
	return (1);
}

int			is_new_cmd(t_cmd *cmd)
{
	if (cmd && (ft_strequ(cmd->operator_type, ";") || !cmd->operator_type))
		return (1);
	return (0);
}

t_cmd		*launcher_errors_controller(t_cmd *cmd)
{
	t_error		*error;
	t_cmd		*begin;
	int			is_an_error;

	begin = cmd;
	is_an_error = 0;
	while (cmd)
	{
		error = errors_init(0, NULL);
		if ((error->number = check_cmd(cmd, &error->details)) < 1)
		{
			launcher_errors_printer(error);
			is_an_error = 1;
		}
		if (is_new_cmd(cmd) && is_an_error)
		{
			begin = cmd->next;
			is_an_error = 0;
		}
		else if (is_new_cmd(cmd) && !is_an_error)
			return (begin);
		errors_delete(&error);
		cmd = cmd->next;
	}
	return (begin);
}
