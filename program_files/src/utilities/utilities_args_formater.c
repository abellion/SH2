/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_args_formater.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:18:29 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:39:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		option_is(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) >= 2 && str[0] == '-')
		return (1);
	return (0);
}

int		option_is_valid(char *curent_options, char *available_options)
{
	int		index;

	if (!curent_options || !available_options)
		return (0);
	index = 1;
	while (curent_options[index])
	{
		if (!ft_strchr(available_options, curent_options[index]))
			return (0);
		index++;
	}
	return ((option_is(curent_options) ? 1 : 0));
}

char	*option_valid_formater(char **args, char *available_options)
{
	int		i;
	char	*formated;

	if (!args || !available_options)
		return (0);
	i = 0;
	formated = NULL;
	while (args[i] && option_is_valid(args[i], available_options))
	{
		formated = (!formated) ? ft_strdup("") : formated;
		formated = ft_strjoin(formated, &args[i][1]);
		i++;
	}
	return (formated);
}

char	*option_unvalid_formater(char **args, char *available_options)
{
	int		i;
	char	*formated;

	if (!args || !available_options)
		return (0);
	i = 0;
	formated = NULL;
	while (args[i] && option_is(args[i]))
	{
		if (!option_is_valid(args[i], available_options) || formated)
		{
			formated = (!formated) ? ft_strdup("") : formated;
			formated = ft_strjoin(formated, &args[i][1]);
		}
		i++;
	}
	return (formated);
}

char	**option_other_formater(char **args, char *available_options)
{
	int		i;
	char	**formated;

	if (!args || !available_options)
		return (0);
	i = 0;
	while (args[i] && option_is_valid(args[i], available_options))
		i++;
	formated = (char **)ft_tabdup((void **)&args[i], &ft_tabdup_str);
	return (formated);
}
