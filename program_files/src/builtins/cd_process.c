/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 17:04:05 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 16:04:52 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

void		cd_process(t_args *args, t_list *env)
{
	char	*path;
	char	*input;

	if (!args)
		return ;
	input = (ft_tablen((void **)args->other) >= 1) ? args->other[0] : NULL;
	path = cd_determine_path(input, env);
	if (path && chdir(path) == 0)
	{
		if (env)
		{
			env = setenv_set("OLDPWD", env_get_from_lst("PWD", env), env);
			env = setenv_set("PWD", path, env);
		}
		ft_strdel(&path);
	}
}
