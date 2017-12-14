/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 21:15:41 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/18 22:48:19 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ret;

	ret = NULL;
	if (lst)
		ret = f(lst);
	if (ret == NULL)
		return (NULL);
	new = ret;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (ret);
}
