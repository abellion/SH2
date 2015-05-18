/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:16:56 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:34:44 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cmd_get_redir_type(char **input)
{
	int		i;
	char	*redir;

	i = 0;
	while (input && input[i])
	{
		redir = cmd_is_redir(input[i], input[i + 1]);
		if (redir)
			return (redir);
		i++;
		ft_strdel(&redir);
	}
	return (0);
}

char	*cmd_get_redir_to(char **input)
{
	int		i;
	int		len;
	int		pos;

	i = 0;
	pos = -1;
	while (input && input[i])
	{
		if (cmd_is_redir(input[i], 0))
		{
			pos = i;
			break ;
		}
		i++;
	}
	len = ft_tablen((void **)input) - 1;
	if (len >= pos + 2 && pos >= 0 && cmd_is_redir(input[pos + 1], 0))
		return (ft_strdup(input[pos + 2]));
	else if (len >= pos + 1 && pos >= 0 && !cmd_is_redir(input[pos + 1], 0))
		return (ft_strdup(input[pos + 1]));
	return (0);
}
