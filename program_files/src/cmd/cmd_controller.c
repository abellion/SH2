/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:52:15 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 21:22:46 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int			cmd_errors_controller(t_cmd *cmd)
{
	t_error		*error;

	error = NULL;
	while (cmd)
	{
		if (!ft_strlen(cmd->name))
			error = errors_init(ERR_NULLCMD, NULL);
		else if (cmd->redirection_type && !ft_strlen(cmd->redirection_to))
			error = errors_init(ERR_REDIRECT, NULL);
		if (error)
			return (errors_controller(error, &cmd_errors_printer), 0);
		cmd = cmd->next;
	}
	return (1);
}

void		cmd_errors_printer(t_error *error)
{
	if (error)
	{
		if (error->number == ERR_NULLCMD)
			ft_putendl_fd("Invalid null command.", 2);
		else if (error->number == ERR_REDIRECT)
			ft_putendl_fd("Missing name for redirect.", 2);
	}
}

t_cmd		*cmd_process(char *input, t_list *env)
{
	t_cmd		*cmd;
	char		**parts;

	cmd = cmd_init();
	parts = cmd_make_parts(input);
	cmd_put(&(cmd), parts, env);
	ft_tabdel((void ***)&parts, ft_tabdel_str);
	return (cmd);
}

t_cmd		*cmd_controller(char *input, t_list *env)
{
	int			i;
	t_cmd		*begin;
	t_cmd		*cmds_lst;
	char		**cmds_tab;

	i = 0;
	cmds_lst = cmd_init();
	begin = cmds_lst;
	input = cmd_clear_exhaust(input);
	cmds_tab = cmd_make_splits(input);
	while (cmds_tab && cmds_tab[i])
	{
		cmds_lst->next = cmd_process(cmds_tab[i], env);
		cmds_lst = cmds_lst->next;
		i++;
	}
	ft_strdel(&input);
	ft_tabdel((void ***)&cmds_tab, ft_tabdel_str);
	begin = cmd_update(begin->next, env);
	return ((cmd_errors_controller(begin)) ? begin : 0);
}
