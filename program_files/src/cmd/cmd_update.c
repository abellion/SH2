/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 13:40:14 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 16:18:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cmd_remove_quot(char *str)
{
	str = 0;
	return (0);
}

char	*cmd_remove_exhaust(char *str)
{
	int		index;
	char	prev;
	char	*new;

	prev = 0;
	index = 0;
	new = ft_strdup("");
	while (str && str[index])
	{
		if (str[index] != '\\' || (str[index] == '\\' && prev == '\\'))
			new = ft_strcjoin(new, "", str[index]);
		prev = str[index];
		index++;
	}
	return (new);
}

char	*cmd_replace_special(char *str, t_list *env)
{
	char	*new;

	new = str;
	if (str && str[0] == '~')
		new = ft_strjoin(env_get_from_lst("HOME", env), &str[1]);
	return (new);
}

char	*cmd_clear_exhaust(char *str)
{
	char	p;
	char	*clr;
	int		i_str;
	int		i_clr;

	p = 0;
	i_str = 0;
	i_clr = 0;
	clr = NULL;
	while (str && str[i_str])
	{
		if (str[i_str] != '\\' || (str[i_str] == '\\' && p != '\\'))
		{
			clr = (!clr) ? ft_strnew(ft_strlen(str)) : clr;
			clr[i_clr] = str[i_str];
			i_clr++;
		}
		p = str[i_str];
		i_str++;
	}
	if (clr)
		return (clr[i_clr] = '\0', clr);
	return (NULL);
}

t_cmd	*cmd_update(t_cmd *cmd, t_list *env)
{
	int		i;
	t_cmd	*begin;

	begin = cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->args && cmd->args[i])
		{
			cmd->args[i] = cmd_replace_special(cmd->args[i], env);
			i++;
		}
		cmd = cmd->next;
	}
	return (begin);
}
