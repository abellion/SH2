/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:11:13 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:34:09 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int			unsetenv_controller(t_cmd *cmd, t_list **env)
{
	int			i;
	t_args		*args;

	if (!cmd || !(args = args_put(cmd, "")))
		return (0);
	i = 0;
	while (env && args->other && args->other[i])
	{
		*env = unsetenv_unset(args->other[i], *env);
		i++;
	}
	args_delete(&args);
	return (1);
}

t_list		*unsetenv_unset(char *name, t_list *env)
{
	t_list		*begin;
	char		**splits;

	if (!name || !env)
		return (0);
	begin = env;
	while (env)
	{
		splits = ft_strsplit(env->content, '=');
		if (splits && ft_strequ(splits[0], name))
		{
			ft_tabdel((void ***)&splits, ft_tabdel_str);
			return (ft_lstpop(begin, env));
		}
		ft_tabdel((void ***)&splits, ft_tabdel_str);
		env = (env)->next;
	}
	return (begin);
}
