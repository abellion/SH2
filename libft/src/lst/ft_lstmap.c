/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:31:05 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:21:50 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*begin;

	if (!lst || !f)
		return (0);
	new_lst = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
	begin = new_lst;
	while ((lst = lst->next))
	{
		temp = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
		new_lst->next = temp;
		new_lst = temp;
	}
	return (begin);
}
