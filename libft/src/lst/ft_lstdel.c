/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 15:36:50 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 18:20:40 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_lst;
	t_list	*temp;

	if (alst && del)
	{
		next_lst = *alst;
		while (next_lst)
		{
			temp = next_lst->next;
			ft_lstdelone(&next_lst, del);
			next_lst = temp;
		}
		*alst = NULL;
	}
}
