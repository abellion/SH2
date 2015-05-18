/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:22:39 by abellion          #+#    #+#             */
/*   Updated: 2015/05/09 17:37:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell2.h"

void	signal_traitment(int signal_number)
{
	ft_putstr("\n");
	prompt_controller(NULL, 0);
	signal_number = 0;
}

void	ft_catch_signal(int i)
{
	if (i == SIGINT || i == SIGCONT || i == SIGTSTP)
		signal_traitment(0);
}

void	ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_catch_signal);
		i++;
	}
}

int		main(void)
{
	extern char		**environ;
	t_list			*env;
	t_cmd			*cmd;
	char			*input;

	ft_signal();
	env = tab_to_lst(environ);
	while ((input = prompt_controller(env, 1)))
	{
		cmd = cmd_controller(input, env);
		launcher_controller(cmd, &env);
		cmd_delall(&cmd);
		ft_strdel(&input);
	}
	ft_putstr("exit\n");
	return (0);
}
