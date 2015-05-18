/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:29:32 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:23:34 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char				*string;
	unsigned int		index;

	if (s)
	{
		index = 0;
		string = (char *)s;
		while (index < n)
		{
			string[index] = '\0';
			index++;
		}
	}
}
