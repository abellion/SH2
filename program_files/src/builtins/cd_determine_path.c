/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_determine_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:10:40 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 17:40:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cd_determine_path(char *path, t_list *env)
{
	char	*home;
	char	pwd[1024];
	char	*final_path;

	if (path)
	{
		getcwd(pwd, 1024);
		path = path_clear(path);
		final_path = path_formater(path, pwd);
	}
	else if (env && (home = env_get_from_lst("HOME", env)))
		final_path = home;
	else
		final_path = ft_strdup("./");
	return (final_path);
}
