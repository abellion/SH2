/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:19:55 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:34:25 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				index;
	unsigned int	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	index = len_s;
	while (!ft_strchr(&s[index], c) && index + 1)
		index--;
	if (index >= 0)
		return ((char *)&s[index]);
	return (0);
}
