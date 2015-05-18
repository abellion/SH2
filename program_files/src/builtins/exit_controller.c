/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:11:00 by abellion          #+#    #+#             */
/*   Updated: 2015/03/14 17:11:02 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_args		*exit_errors_controller(t_cmd *cmd)
{
	t_args		*args;
	t_error		*error;

	if (!cmd || !(args = args_put(cmd, "")))
		return (0);
	error = NULL;
	if (args->unvalid)
		error = errors_init(ERR_USAGE, args->unvalid);
	if (error)
		return (errors_controller(error, &exit_errors_printer), NULL);
	return (args);
}

void		exit_errors_printer(t_error *error)
{
	if (error && error->number == ERR_USAGE)
		ft_putstr_fd("exit : usage : exit", 2);
}

int			exit_controller(t_cmd *cmd, t_list **env)
{
	t_args		*args;

	if (!cmd || !(args = exit_errors_controller(cmd)))
		return (0);
	args_delete(&args);
	cmd_delall(&cmd);
	ft_lstdel(env, del);
	ft_putstr("exit\n");
	exit(EXIT_SUCCESS);
	return (1);
}
