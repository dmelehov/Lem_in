/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:14:01 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:40 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_mylist_cell	*ft_list_insert(t_mylist *v_this,
				t_mylist_cell *position, void *data)
{
	t_mylist_cell	*cell;

	if (position == NULL)
	{
		if (D_LIST(push_back)(v_this, data) == true)
			return (D_LIST(end)(v_this));
		else
			return (NULL);
	}
	cell = D_LIST_CELL(create)(position->v_prev, position, data);
	if (cell != NULL)
	{
		if (D_LIST_CELL(prev)(position) != NULL)
			D_LIST_CELL(prev)(position)->v_next = cell;
		else
			v_this->v_begin = cell;
		position->v_prev = cell;
		v_this->v_size = D_LIST(size)(v_this) + 1;
	}
	return (cell);
}
