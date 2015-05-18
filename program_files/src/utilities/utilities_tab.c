/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:38:55 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 19:45:20 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	**tab_join(char **tab1, char **tab2)
{
	char	**new_tab;
	char	*tmp;
	int		len_new_tab;
	int		count;
	int		index;

	len_new_tab = (ft_tablen((void **)tab1) + ft_tablen((void **)tab2)) + 1;
	new_tab = (char **)malloc(sizeof(char *) * len_new_tab);
	if (!tab1 || !tab2 || !new_tab)
		return (0);
	index = 0;
	count = 0;
	while (count < (len_new_tab - 1))
	{
		if (tab1 && !tab1[index])
		{
			tab1 = NULL;
			index = 0;
		}
		tmp = (tab1) ? tab1[index] : tab2[index];
		new_tab[count] = ft_strdup(tmp);
		index++, count++;
	}
	new_tab[count] = NULL;
	return (new_tab);
}

char	*tab_to_str(char **tab)
{
	char	*str;
	char	*tmp;
	int		index;

	index = 0;
	str = NULL;
	while (tab && tab[index])
	{
		str = (!str) ? ft_strdup("") : str;
		tmp = str;
		str = ft_strjoin(str, tab[index]);
		ft_strdel(&tmp);
		index++;
	}
	return (str);
}
