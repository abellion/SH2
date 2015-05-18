/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:39:18 by abellion          #+#    #+#             */
/*   Updated: 2015/05/08 20:59:49 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		tmp->content = (void *)malloc(content_size);
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}
