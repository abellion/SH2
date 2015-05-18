/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_path_formater.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:43:46 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 15:02:00 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*path_formater(char *path, char *cwd)
{
	int		len;
	int		index;
	char	**splits;
	char	*new_path;

	index = 0;
	new_path = NULL;
	path = (path[0] != '/') ? ft_strcjoin(cwd, path, '/') : path;
	splits = ft_strsplit(path, '/');
	while (splits && splits[index])
	{
		new_path = (!new_path) ? ft_strdup("") : new_path;
		len = ft_strlen(new_path) - ft_strlen(ft_strrchr(new_path, '/'));
		if (ft_strequ(splits[index], "..") && !ft_strequ(new_path, "/"))
			new_path = ft_strsub(new_path, 0, len);
		else if (!ft_strequ(splits[index], ".."))
			new_path = ft_strcjoin(new_path, splits[index], '/');
		index++;
	}
	ft_tabdel((void ***)&splits, ft_tabdel_str);
	return ((!ft_strlen(new_path)) ? ft_strdup("/") : new_path);
}

char	*path_clear(char *path)
{
	int		index;
	char	**splits;
	char	*new_path;

	index = 0;
	new_path = NULL;
	splits = ft_strsplit(path, '/');
	while (splits && splits[index])
	{
		if (!ft_strequ(splits[index], "."))
		{
			new_path = (!new_path) ? ft_strdup("") : new_path;
			if (ft_strlen(new_path) || path[0] == '/')
				new_path = ft_strcjoin(new_path, splits[index], '/');
			else
				new_path = ft_strjoin(new_path, splits[index]);
		}
		index++;
	}
	return ((!new_path) ? ft_strdup("/") : new_path);
}
