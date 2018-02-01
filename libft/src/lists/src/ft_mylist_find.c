/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:49:22 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/29 17:09:53 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_mylist_cell	*ft_list_find(t_mylist *v_this,
				bool (*cmp)(void *, void *), void *d)
{
	t_mylist_cell	*cell;

	cell = D_LIST(begin)(v_this);
	while (cell != NULL)
	{
		if (cmp(cell->v_data, d) == true)
			break ;
		cell = cell->v_next;
	}
	return (cell);
}
