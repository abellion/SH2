/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:54:08 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:33:44 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnew(size_t size)
{
	char	*allocation;

	if ((allocation = (char *)ft_memalloc(sizeof(char) * (size + 1))))
	{
		allocation[size] = '\0';
		return (allocation);
	}
	return (0);
}
