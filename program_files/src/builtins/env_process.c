/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 15:23:42 by abellion          #+#    #+#             */
/*   Updated: 2015/05/07 18:03:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_list		*env_set(char **args, t_list *env)
{
	int		index;
	char	**splits;

	if (!args)
		return (env);
	index = 0;
	while (args[index] && ft_strchr(args[index], '='))
	{
		splits = ft_strsplit(args[index], '=');
		env = setenv_set(splits[0], splits[1], env);
		ft_tabdel((void ***)&splits, ft_tabdel_str);
		index++;
	}
	return (env);
}

int			env_launcher(char **args, t_list *env)
{
	int		i;
	t_cmd	*cmd;
	char	*input;

	if (!args)
		return (0);
	i = 0;
	input = NULL;
	while (args[i])
	{
		if ((!option_is(args[i]) && !ft_strchr(args[i], '=')) || input)
		{
			input = (!input) ? ft_strdup("") : input;
			input = ft_strcjoin(input, args[i], ' ');
		}
		i++;
	}
	if (input)
	{
		cmd = cmd_controller(input, env);
		launcher_controller(cmd, &env);
		return (1);
	}
	return (0);
}

void		env_process(t_args *args, t_list *env)
{
	t_list		*env_tmp;
	int			launcher_ret;

	if (!args)
		return ;
	env_tmp = (ft_strchr(args->valid, 'i') || !env) ? NULL : ft_lstdup(env);
	env_tmp = env_set(args->other, env_tmp);
	launcher_ret = env_launcher(args->other, env_tmp);
	if ((ft_strchr(args->valid, 'i') && !launcher_ret) || !launcher_ret)
		disp_lst(env_tmp);
	ft_lstdel(&env_tmp, del);
}
