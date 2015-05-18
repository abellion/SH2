/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:27:25 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:01:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

int		cmd_is_arg(char *str, t_cmd *cmd)
{
	if (ft_strequ(str, cmd->operator_type))
		return (0);
	if (ft_strequ(str, cmd->redirection_to) || cmd_is_redir(str, 0))
		return (0);
	return (1);
}

int		cmd_nb_args(char **input, t_cmd *cmd)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (cmd && input && input[i])
	{
		nb += (cmd_is_arg(input[i], cmd)) ? 1 : 0;
		i++;
	}
	return (nb);
}

char	**cmd_get_args(char **input, t_cmd *cmd)
{
	int		nb;
	int		i_args;
	char	**args;
	int		i_input;

	nb = cmd_nb_args(input, cmd);
	args = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!nb || !args || !input || !cmd)
		return (0);
	i_args = 0;
	i_input = 0;
	while (input[i_input])
	{
		if (cmd_is_arg(input[i_input], cmd))
		{
			args[i_args] = ft_strdup(input[i_input]);
			i_args++;
		}
		i_input++;
	}
	args[i_args] = NULL;
	return (args);
}
