/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:30:38 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 14:53:28 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *current;

	head = NULL;
	if (!lst)
		return (NULL);
	if (lst)
	{
		if (!(head = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		head = f(lst);
	}
	lst = lst->next;
	current = head;
	while (lst)
	{
		current->next = f(lst);
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
