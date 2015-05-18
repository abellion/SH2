/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_args_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:18:33 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:39:44 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_args		*args_init(void)
{
	t_args		*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (0);
	args->valid = NULL;
	args->unvalid = NULL;
	args->other = NULL;
	return (args);
}

t_args		*args_put(t_cmd *cmd, char *available_options)
{
	t_args		*args;
	char		**args_tab;

	if (!cmd || !available_options)
		return (0);
	if (ft_tablen((void **)cmd->args) >= 2)
		args_tab = &cmd->args[1];
	else
		args_tab = NULL;
	args = args_init();
	args->valid = option_valid_formater(args_tab, available_options);
	args->unvalid = option_unvalid_formater(args_tab, available_options);
	args->other = option_other_formater(args_tab, available_options);
	return (args);
}

void		args_delete(t_args **args)
{
	if (args && *args)
	{
		ft_strdel(&(*args)->valid);
		ft_strdel(&(*args)->unvalid);
		ft_tabdel((void ***)&(*args)->other, ft_tabdel_str);
		free(*args);
		*args = NULL;
	}
}
