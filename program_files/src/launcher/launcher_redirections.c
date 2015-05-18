/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:15:23 by abellion          #+#    #+#             */
/*   Updated: 2015/03/14 17:15:40 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		redirection_right(t_cmd *cmd)
{
	int		fd;

	if (!cmd)
		return (0);
	fd = -1;
	if (ft_strequ(cmd->redirection_type, ">"))
		fd = open(cmd->redirection_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strequ(cmd->redirection_type, ">>"))
		fd = open(cmd->redirection_to, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (0);
	dup2(fd, 1);
	close(fd);
	return (1);
}

int		redirection_s_left(t_cmd *cmd)
{
	int		fd;

	if (!cmd)
		return (0);
	if ((fd = open(cmd->redirection_to, O_RDONLY)) < 0)
		return (0);
	dup2(fd, 0);
	close(fd);
	return (1);
}

char	*input_d_left(char *str_stop)
{
	char	*input;
	char	*tmp;
	char	*line;

	if (!str_stop)
		return (0);
	tmp = NULL;
	input = NULL;
	ft_putstr("> ");
	while (!ft_strequ(tmp, str_stop) && get_next_line(0, &line))
	{
		ft_strdel(&tmp);
		if (!ft_strequ(line, str_stop))
		{
			input = (!input) ? ft_strdup("") : input;
			input = ft_strcjoin(input, line, '\n');
			ft_putstr("> ");
		}
		tmp = ft_strdup(line);
		free(line);
	}
	ft_strdel(&tmp);
	input = ft_strcjoin(input, "", '\n');
	return (ft_strsub(input, 1, ft_strlen(input)));
}

int		redirection_d_left(t_cmd *cmd)
{
	char	*input;
	int		fd[2];

	if (!cmd)
		return (0);
	pipe(fd);
	input = input_d_left(cmd->redirection_to);
	ft_putstr_fd(input, fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	ft_strdel(&input);
	return (1);
}

int		redirection_controller(t_cmd *cmd)
{
	char	*redirection;

	if (!cmd)
		return (0);
	while (cmd)
	{
		redirection = cmd->redirection_type;
		if (ft_strequ(redirection, ">") || ft_strequ(redirection, ">>"))
			redirection_right(cmd);
		else if (ft_strequ(redirection, "<"))
			redirection_s_left(cmd);
		else if (ft_strequ(redirection, "<<"))
			redirection_d_left(cmd);
		cmd = (!is_new_cmd(cmd) ? cmd->next : NULL);
	}
	return (1);
}
