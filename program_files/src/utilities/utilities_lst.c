/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:12:07 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 20:59:26 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char		**lst_to_tab(t_list *lst)
{
	int			nb_links;
	int			index;
	char		**tab;

	nb_links = ft_lstcount(lst);
	if (!lst || !(tab = (char **)malloc(sizeof(char *) * (nb_links + 1))))
		return (0);
	index = 0;
	while (lst)
	{
		tab[index] = ft_strdup(lst->content);
		index++;
		lst = lst->next;
	}
	tab[index] = NULL;
	return (tab);
}

t_list		*tab_to_lst(char **tab)
{
	int			i;
	t_list		*lst;
	t_list		*begin;

	if (!tab)
		return (0);
	i = 0;
	lst = ft_lstnew(NULL, 0);
	begin = lst;
	while (tab[i])
	{
		lst->next = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
		lst = lst->next;
		i++;
	}
	lst = begin->next;
	ft_lstdelone(&begin, del);
	return (lst);
}

t_cmd		*cmd_pop(t_cmd *lst, t_cmd *elem)
{
	t_cmd	*prev;
	t_cmd	*tmp;
	t_cmd	*begin;

	if (!lst || !elem)
		return (0);
	prev = NULL;
	begin = lst;
	while (lst && lst != elem)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = lst->next;
	else
		tmp = begin->next;
	cmd_delone(&lst);
	return ((prev) ? begin : tmp);
}

void		disp_lst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putstr("\n");
		lst = lst->next;
	}
}
