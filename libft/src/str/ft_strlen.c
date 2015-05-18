/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:20:57 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 20:52:07 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t		ft_strlen(const char *s)
{
	const char	*cpy;

	if (!s)
		return (0);
	cpy = s;
	while (*s)
		s++;
	return (s - cpy);
}
