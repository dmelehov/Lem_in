/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:34:32 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/25 13:12:35 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void					*ft_list_back(t_mylist *v_this)
{
	if (v_this->v_end != NULL)
		return (v_this->v_end->v_data);
	return (NULL);
}

void					*ft_list_front(t_mylist *v_this)
{
	if (v_this->v_begin != NULL)
		return (v_this->v_begin->v_data);
	return (NULL);
}

t_mylist_cell			*ft_list_begin(const t_mylist *v_this)
{
	return (v_this->v_begin);
}

t_mylist_cell			*ft_list_end(const t_mylist *v_this)
{
	return (v_this->v_end);
}

t_mylist_cell			*ft_list_get_cell(t_mylist *list, size_t cell_at)
{
	size_t			i;
	t_mylist_cell	*cur;

	i = 0;
	cur = list->v_begin;
	while (cur != NULL && i < cell_at)
	{
		cur = cur->v_next;
		i = i + 1;
	}
	return (cur);
}
