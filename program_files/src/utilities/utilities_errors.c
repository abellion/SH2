/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:09:01 by abellion          #+#    #+#             */
/*   Updated: 2015/03/06 18:41:35 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

t_error		*errors_init(int number, char *details)
{
	t_error		*error;

	if (!(error = (t_error *)malloc(sizeof(t_error))))
		return (0);
	error->number = number;
	error->details = ft_strdup(details);
	return (error);
}

void		errors_delete(t_error **error)
{
	if (error && *error)
	{
		ft_strdel(&(*error)->details);
		free(*error);
		*error = NULL;
	}
}

void		errors_controller(t_error *error, t_printer printer_fun)
{
	if (error && printer_fun)
	{
		(printer_fun)(error);
		errors_delete(&error);
	}
}
