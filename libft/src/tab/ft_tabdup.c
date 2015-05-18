/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:22:01 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:47:43 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_tabdup_str(void *str)
{
	return (ft_strdup(str));
}

void	**ft_tabdup(void **tab, void *(*dup)(void *))
{
	int		i;
	int		len;
	void	**new;

	i = 0;
	len = ft_tablen(tab);
	if (!tab || !(new = (void **)malloc(sizeof(void *) * (len + 1))))
		return (0);
	while (tab && tab[i])
	{
		new[i] = (dup)(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
