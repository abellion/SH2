/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:11:42 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:23:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == '\0' && c == '\0')
		return ((char *)&s[index]);
	return (0);
}
