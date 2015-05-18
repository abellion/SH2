/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:55:20 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:34:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cmd_get_operator(char **input)
{
	int		len;

	len = ft_tablen((void **)input) - 1;
	if (len > 0 && ft_strlen(input[len]) == 1 && cmd_is_operator(input[len][0]))
		return (ft_strdup(input[len]));
	return (0);
}
