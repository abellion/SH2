/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_errors_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:23:39 by abellion          #+#    #+#             */
/*   Updated: 2015/03/06 18:27:30 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

void	launcher_errors_printer(t_error *error)
{
	if (error)
	{
		ft_putstr_fd("minishell : ", 2);
		if (error->number == ERR_NOTFOUND)
			ft_putstr_fd("command not found : ", 2);
		else if (error->number == ERR_NORIGHTS)
			ft_putstr_fd("permission denied : ", 2);
		else if (error->number == ERR_NOFILE)
			ft_putstr_fd("no such file or directory : ", 2);
		ft_putstr_fd(error->details, 2);
		ft_putchar_fd('\n', 2);
	}
}
