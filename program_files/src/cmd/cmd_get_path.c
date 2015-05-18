/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 10:16:30 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 15:14:37 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	**cmd_get_paths(t_list *env)
{
	extern char		**environ;
	char			**paths;

	if (env && env_get_from_lst("PATH", env))
		paths = ft_strsplit(env_get_from_lst("PATH", env), ':');
	else
		paths = ft_strsplit(env_get_from_tab("PATH", environ), ':');
	return (paths);
}

char	*cmd_path_search(char *cmd_name, char **paths)
{
	char			*path;
	char			*rights;
	int				index;

	index = 0;
	while (cmd_name && paths && paths[index])
	{
		path = ft_strcjoin(paths[index], cmd_name, '/');
		rights = path_checker_rights(path);
		if (ft_strchr(rights, 'x'))
			return (ft_strdel(&rights), path);
		ft_strdel(&rights);
		ft_strdel(&path);
		index++;
	}
	return (0);
}

char	*cmd_get_path(char **input, t_list *env)
{
	char			**paths;
	char			*cmd_name;
	char			*cmd_path;
	char			pwd[1024];

	if (!input || !*input)
		return (0);
	getcwd(pwd, 1024);
	paths = cmd_get_paths(env);
	cmd_name = cmd_get_name(input);
	if (cmd_name && cmd_name[0] == '.')
		cmd_path = ft_strcjoin(pwd, cmd_name, '/');
	else if (cmd_name && cmd_name[0] == '/')
		cmd_path = ft_strdup(cmd_name);
	else
		cmd_path = cmd_path_search(cmd_name, paths);
	ft_tabdel((void ***)&paths, ft_tabdel_str);
	ft_strdel(&cmd_name);
	return (cmd_path);
}
