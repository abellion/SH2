/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_make_splits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:40:07 by abellion          #+#    #+#             */
/*   Updated: 2015/05/06 17:42:51 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int			cmd_nb_split(char *input)
{
	int		i;
	int		nb;
	char	prev;
	int		separator;

	i = 0;
	nb = 0;
	prev = 0;
	while (input && input[i])
	{
		separator = cmd_is_operator(input[i]);
		if (separator || !input[i + 1])
			nb++;
		i++;
		prev = input[i];
	}
	return (nb);
}

char		*cmd_next_split(char *input)
{
	int		i;
	char	prev;
	int		separator;

	i = 0;
	prev = 0;
	while (input && input[i])
	{
		separator = cmd_is_operator(input[i]);
		if (separator || !input[i + 1])
			return (ft_strsub(input, 0, i + 1));
		i++;
		prev = input[i];
	}
	return (0);
}

char		**cmd_make_splits(char *input)
{
	int		i;
	int		nb;
	char	**splits;

	i = 0;
	nb = cmd_nb_split(input);
	splits = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!input || !nb || !splits)
		return (0);
	while (input && input[0] && i < nb)
	{
		splits[i] = cmd_next_split(input);
		input = &input[ft_strlen(splits[i])];
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
