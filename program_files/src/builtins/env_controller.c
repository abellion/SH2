/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:10:53 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 16:15:24 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_args		*env_errors_controller(t_cmd *cmd)
{
	t_args		*args;
	t_error		*error;

	if (!cmd || !(args = args_put(cmd, "i")))
		return (0);
	if (args->unvalid)
	{
		error = errors_init(ERR_USAGE, args->unvalid);
		return (errors_controller(error, &env_errors_printer), NULL);
	}
	return (args);
}

void		env_errors_printer(t_error *error)
{
	if (error && error->number == ERR_USAGE)
	{
		ft_putstr_fd("env : illegal option -- ", 2);
		ft_putchar_fd(error->details[0], 2);
		ft_putstr_fd("\nusage : env [-i] [name=value ...] ", 2);
		ft_putstr_fd("[utility [argument ...]]\n", 2);
	}
}

int			env_controller(t_cmd *cmd, t_list **env)
{
	t_args		*args;

	if (!cmd || !(args = env_errors_controller(cmd)))
		return (0);
	if (env && *env)
		env_process(args, *env);
	else
		env_process(args, NULL);
	args_delete(&args);
	return (0);
}
