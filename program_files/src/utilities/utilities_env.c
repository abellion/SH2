/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:25 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:39:51 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char		*env_get_from_tab(char *to_get, char **env)
{
	int			index;
	char		**ret;
	char		*tmp;

	if (!to_get || !env)
		return (0);
	index = 0;
	while (env[index])
	{
		ret = ft_strsplit(env[index], '=');
		if (ft_tablen((void **)ret) == 2 && ft_strequ(ret[0], to_get))
		{
			tmp = ft_strdup(ret[1]);
			ft_tabdel((void ***)&ret, ft_tabdel_str);
			return (tmp);
		}
		ft_tabdel((void ***)&ret, ft_tabdel_str);
		index++;
	}
	return (0);
}

char		*env_get_from_lst(char *to_get, t_list *env)
{
	char		**ret;
	char		*tmp;

	if (!to_get || !env)
		return (0);
	while (env)
	{
		ret = ft_strsplit(env->content, '=');
		if (!ft_strcmp(ret[0], to_get))
		{
			tmp = ft_strdup(ret[1]);
			ft_tabdel((void ***)&ret, ft_tabdel_str);
			return (tmp);
		}
		ft_tabdel((void ***)&ret, ft_tabdel_str);
		env = env->next;
	}
	return (0);
}
