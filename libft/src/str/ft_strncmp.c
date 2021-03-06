/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:44:34 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:32:45 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*new_s1;
	char	*new_s2;
	int		cmp;

	if (!s1 || !s2)
		return (0);
	new_s1 = ft_strncpy(ft_strnew(n), s1, n);
	new_s2 = ft_strncpy(ft_strnew(n), s2, n);
	cmp = ft_strcmp(new_s1, new_s2);
	ft_strdel(&new_s1);
	ft_strdel(&new_s2);
	return (cmp);
}
