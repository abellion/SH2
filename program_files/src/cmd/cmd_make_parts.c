/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_make_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:39:43 by abellion          #+#    #+#             */
/*   Updated: 2015/05/06 17:48:18 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int			cmd_nb_parts(char *input)
{
	int		nb;
	char	*part;

	nb = 0;
	while (cmd_next_part(input))
	{
		part = cmd_next_part(input);
		input = &input[ft_strlen(part)];
		part = ft_strtrim(part);
		if (ft_strlen(part))
			nb++;
	}
	return (nb);
}

char		*cmd_next_part(char *input)
{
	int		i;
	char	p;
	int		len;

	i = 0;
	p = 0;
	while (input && input[i])
	{
		if (cmd_is_separator(input[i], input[i + 1]))
		{
			if (i && (input[i + 1] || cmd_is_operator(input[i])))
				len = i;
			else
				len = i + 1;
			return (ft_strsub(input, 0, len));
		}
		p = input[i];
		i++;
	}
	return (0);
}

char		**cmd_make_parts(char *input)
{
	int		i;
	int		nb;
	char	*part;
	char	**parts;

	i = 0;
	nb = cmd_nb_parts(input);
	parts = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!input || !nb || !parts)
		return (0);
	while (cmd_next_part(input))
	{
		part = cmd_next_part(input);
		input = &input[ft_strlen(part)];
		part = ft_strtrim(part);
		if (ft_strlen(part))
			parts[i] = part, i++;
		else
			ft_strdel(&part);
	}
	parts[i] = NULL;
	return (parts);
}
