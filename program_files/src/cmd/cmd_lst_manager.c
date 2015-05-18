/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:43:39 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 15:14:57 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_cmd		*cmd_init(void)
{
	t_cmd		*cmd;

	if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd))))
		return (0);
	cmd->name = NULL;
	cmd->path = NULL;
	cmd->args = NULL;
	cmd->operator_type = NULL;
	cmd->redirection_type = NULL;
	cmd->redirection_to = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd		*cmd_remove_empty(t_cmd *cmd)
{
	t_cmd		*begin;

	begin = cmd;
	while (cmd)
	{
		if (!ft_strlen(cmd->name))
			begin = cmd_pop(begin, cmd);
		cmd = cmd->next;
	}
	return (begin);
}

void		cmd_put(t_cmd **cmd, char **parts, t_list *env)
{
	if (!cmd || !*cmd || !parts || !*parts)
		return ;
	(*cmd)->name = cmd_get_name(parts);
	(*cmd)->path = cmd_get_path(parts, env);
	(*cmd)->redirection_type = cmd_get_redir_type(parts);
	(*cmd)->redirection_to = cmd_get_redir_to(parts);
	(*cmd)->operator_type = cmd_get_operator(parts);
	(*cmd)->args = cmd_get_args(parts, (*cmd));
}

void		cmd_delone(t_cmd **cmd)
{
	if (cmd && *cmd)
	{
		ft_strdel(&(*cmd)->name);
		ft_strdel(&(*cmd)->path);
		ft_tabdel((void ***)&(*cmd)->args, ft_tabdel_str);
		ft_strdel(&(*cmd)->operator_type);
		ft_strdel(&(*cmd)->redirection_type);
		ft_strdel(&(*cmd)->redirection_to);
		free(*cmd);
		*cmd = NULL;
	}
}

void		cmd_delall(t_cmd **cmd)
{
	t_cmd	*next;

	while (cmd && *cmd)
	{
		next = (*cmd)->next;
		cmd_delone(&(*cmd));
		*cmd = next;
	}
}
