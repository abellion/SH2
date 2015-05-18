/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:44:27 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 21:22:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		cmd_is_quot(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int		cmd_is_operator(char c)
{
	if ((c == '|' || c == ';'))
		return (1);
	return (0);
}

char	*cmd_is_redir(char *c, char *s)
{
	if (ft_strequ(c, ">") && ft_strequ(s, ">"))
		return (ft_strjoin(c, s));
	else if (ft_strequ(c, "<") && ft_strequ(s, "<"))
		return (ft_strjoin(c, s));
	else if (ft_strequ(c, ">") || ft_strequ(c, "<"))
		return (ft_strdup(c));
	return (0);
}

int		cmd_is_separator(char c, char s)
{
	if (c == ' ' || c == '\t')
		return (1);
	else if (cmd_is_operator(c) || cmd_is_redir(ft_atos(c), ft_atos(s)))
		return (1);
	else if (!s)
		return (1);
	return (0);
}

int		cmd_find_quot(char c, char p)
{
	static char		delimiter;

	if (p != '\\' && (c == '\'' || c == '\"'))
	{
		if (!delimiter)
		{
			delimiter = c;
			return (c);
		}
		else if (delimiter && c == delimiter)
		{
			delimiter = 0;
			return (c);
		}
	}
	return ((delimiter) ? delimiter : 0);
}
