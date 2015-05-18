/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:10:47 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:29:52 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		index;

	index = 0;
	if (!f || !s || !(new_str = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[index])
	{
		new_str[index] = (*f)(index, s[index]);
		index++;
	}
	return (new_str);
}
