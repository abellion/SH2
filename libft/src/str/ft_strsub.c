/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:10:07 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:34:50 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	index;

	index = start;
	if (!s || !(new_str = ft_strnew(len)))
		return (0);
	while (index < (start + len))
	{
		new_str[index - start] = s[index];
		index++;
	}
	return (new_str);
}
