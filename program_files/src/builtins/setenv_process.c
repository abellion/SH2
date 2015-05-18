/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:01:41 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:34:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_list		*setenv_set(char *name, char *value, t_list *env)
{
	char		*new;
	t_list		*prev;
	t_list		*begin;
	char		**splits;

	begin = env;
	prev = NULL;
	value = (!value) ? ft_strdup("") : value;
	name = (!name) ? ft_strdup("") : name;
	new = ft_strcjoin(name, value, '=');
	while (env)
	{
		splits = ft_strsplit(env->content, '=');
		if (!ft_strcmp(splits[0], name))
			return (env->content = new, begin);
		prev = env;
		env = env->next;
	}
	if (prev)
		prev->next = ft_lstnew(new, ft_strlen(new) + 1);
	else
		begin = ft_lstnew(new, ft_strlen(new) + 1);
	ft_strdel(&new);
	return (begin);
}

t_list		*setenv_process(t_args *args, t_list *env)
{
	char		*name;
	char		*value;

	if (!args)
		return (0);
	if (args->other)
	{
		name = (ft_tablen((void **)args->other) >= 1) ? args->other[0] : NULL;
		value = (ft_tablen((void **)args->other) >= 2) ? args->other[1] : NULL;
		env = setenv_set(name, value, env);
	}
	else if (env)
		disp_lst(env);
	return (env);
}
