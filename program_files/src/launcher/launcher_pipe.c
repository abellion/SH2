/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:44:16 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 17:35:59 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		run_pipe(t_cmd *cmd, t_list **env, int *fd)
{
	static int	fd_in;
	pid_t		prog_id;

	if (!cmd || !fd)
		return (0);
	fd_in = (!fd_in) ? 0 : fd_in;
	prog_id = fork();
	if (prog_id == 0)
	{
		dup2(fd_in, 0);
		dup2((!is_new_cmd(cmd)) ? fd[1] : -1, 1);
		close(fd[1]);
		launcher_normal(cmd, env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		fd_in = fd[0];
	}
	return (1);
}

int		launcher_pipe(t_cmd *cmd, t_list **env)
{
	int			fd[2];

	while (cmd)
	{
		pipe(fd);
		run_pipe(cmd, env, fd);
		cmd = (!is_new_cmd(cmd)) ? cmd->next : NULL;
	}
	return (1);
}
