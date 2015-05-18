/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:10:30 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:33:24 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_args		*cd_errors_controller(t_cmd *cmd)
{
	t_args		*args;
	t_error		*error;
	char		*rights;

	if (!cmd || !(args = args_put(cmd, "p")))
		return (0);
	error = NULL;
	if (args->unvalid)
		error = errors_init(ERR_USAGE, "");
	else if (args->other && ft_tablen((void **)args->other) >= 1)
	{
		rights = path_checker_rights(args->other[0]);
		if (ft_tablen((void **)args->other) > 1)
			error = errors_init(ERR_MANY, "");
		else if (!rights)
			error = errors_init(ERR_NOFILE, args->other[0]);
		else if (!path_checker_isdir(args->other[0]))
			error = errors_init(ERR_NOTDIR, args->other[0]);
		else if (!ft_strchr(rights, 'r'))
			error = errors_init(ERR_NORIGHTS, args->other[0]);
	}
	if (error)
		return (errors_controller(error, &cd_errors_printer), NULL);
	return (args);
}

void		cd_errors_printer(t_error *error)
{
	if (error)
	{
		ft_putstr_fd("cd : ", 2);
		if (error->number == ERR_USAGE)
			ft_putstr_fd("usage : cd [-p][directory]", 2);
		if (error->number == ERR_MANY)
			ft_putstr_fd("Too many argument.", 2);
		if (error->number == ERR_NOFILE)
			ft_putstr_fd("no such file or directory : ", 2);
		if (error->number == ERR_NOTDIR)
			ft_putstr_fd("not a directory : ", 2);
		if (error->number == ERR_NORIGHTS)
			ft_putstr_fd("permission denied : ", 2);
		if (error->number != ERR_USAGE)
			ft_putstr_fd(error->details, 2);
		ft_putstr_fd("\n", 2);
	}
}

int			cd_controller(t_cmd *cmd, t_list **env)
{
	t_args		*args;

	if (!cmd || !(args = cd_errors_controller(cmd)))
		return (0);
	if (env)
		cd_process(args, *env);
	else
		cd_process(args, NULL);
	args_delete(&args);
	return (1);
}
