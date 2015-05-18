/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:16:18 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:34:26 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cmd_get_name(char **input)
{
	int		len;
	char	*redir;

	if (!input)
		return (0);
	len = ft_tablen((void **)input);
	redir = (len >= 2) ? cmd_is_redir(input[0], input[1]) : NULL;
	if (redir)
	{
		if (ft_strlen(redir) == 2)
			return (ft_strdup(input[3]));
		return (ft_strdup(input[2]));
	}
	return (ft_strdup(input[0]));
}
