/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:47:11 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 20:04:51 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	char				tmp[n];
	char				*src_cpy;
	char				*dst_cpy;

	if (!src || !dst)
		return (0);
	i = 0;
	src_cpy = (char *)src;
	dst_cpy = (char *)dst;
	while (i < n)
	{
		tmp[i] = src_cpy[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = tmp[i];
		i++;
	}
	return (dst_cpy);
}
