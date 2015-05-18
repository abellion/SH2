/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:15 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:27:37 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_string;

	if (!s1 || !(new_string = ft_strnew(ft_strlen(s1))))
		return (0);
	return (ft_strcpy(new_string, s1));
}
