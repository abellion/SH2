/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 18:51:03 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:24:46 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strcjoin(char const *s1, char const *s2, char const c)
{
	char	*new;

	if (!s1 || !s2 || !c)
		return (0);
	new = ft_strjoin(s1, ft_atos(c));
	new = ft_strjoin(new, s2);
	return (new);
}
