/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:17:09 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:22:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *src_cpy;

	if (!dst || !src)
		return (0);
	src_cpy = ft_strdup((char *)src);
	return (ft_strncpy(dst, src_cpy, n));
}
