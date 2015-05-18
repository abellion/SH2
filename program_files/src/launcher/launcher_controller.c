/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:48:26 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 17:35:59 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_cmd	*move_to_next(t_cmd *cmd)
{
	while (cmd && !is_new_cmd(cmd) && cmd)
		cmd = cmd->next;
	return ((cmd) ? cmd->next : cmd);
}

int		is_pipe(t_cmd *cmd)
{
	if (cmd && ft_strequ(cmd->operator_type, "|"))
		return (1);
	return (0);
}

int		launcher_controller(t_cmd *cmd, t_list **env)
{
	int		std_out;
	int		std_in;

	if (!cmd)
		return (0);
	std_in = dup(0);
	std_out = dup(1);
	while ((cmd = launcher_errors_controller(cmd)))
	{
		redirection_controller(cmd);
		if (is_pipe(cmd))
			launcher_pipe(cmd, env);
		else
			launcher_normal(cmd, env);
		dup2(std_out, 1);
		dup2(std_in, 0);
		cmd = move_to_next(cmd);
	}
	return (0);
}
