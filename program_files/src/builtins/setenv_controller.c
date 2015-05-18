/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:11:06 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 16:09:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_args		*setenv_errors_controller(t_cmd *cmd)
{
	t_args		*args;
	t_error		*error;

	if (!cmd || !(args = args_put(cmd, "")))
		return (0);
	error = NULL;
	if (ft_tablen((void **)args->other) > 2)
		error = errors_init(ERR_MANY, "");
	else if (ft_tablen((void **)args->other) >= 1
			&& ft_strchr(args->other[0], '='))
		error = errors_init(ERR_FORMAT, "");
	if (error)
		return (errors_controller(error, &setenv_errors_printer), NULL);
	return (args);
}

void		setenv_errors_printer(t_error *error)
{
	if (error && error->number == ERR_MANY)
		ft_putstr_fd("setenv : Too many argument.\n", 2);
	else if (error && error->number == ERR_FORMAT)
		ft_putstr_fd("setenv : Syntax error.\n", 2);
}

int			setenv_controller(t_cmd *cmd, t_list **env)
{
	t_args		*args;

	if (!cmd || !(args = setenv_errors_controller(cmd)))
		return (0);
	*env = setenv_process(args, *env);
	args_delete(&args);
	return (1);
}
