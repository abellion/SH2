/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:09:36 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:23:09 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*string_cpy;
	unsigned int	index;

	if (!b)
		return (0);
	index = 0;
	string_cpy = (char *)b;
	while (index < len)
	{
		string_cpy[index] = c;
		index++;
	}
	return (string_cpy);
}
