/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:50:43 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:26:56 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	index;
	unsigned int	len_src;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	index = 0;
	while (index <= len_src)
	{
		dst[index] = src[index];
		index++;
	}
	return (dst);
}
