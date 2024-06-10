/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:04:44 by lgosselk          #+#    #+#             */
/*   Updated: 2023/10/30 11:51:27 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_new(void *content, void (*del)(void *))
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
	{
		del(content);
		return (NULL);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst != NULL)
	{
		new = ft_new((*f)(lst->content), del);
		if (!new)
			return (NULL);
		temp = new;
		while (lst->next)
		{
			lst = lst->next;
			temp->next = ft_new((*f)(lst->content), del);
			if (temp->next == NULL)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			temp = temp->next;
		}
		return (new);
	}
	return (NULL);
}
