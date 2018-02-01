/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:43:16 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/23 21:15:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_mylist_cell			*ft_list_cell_create(t_mylist_cell *prev,
										t_mylist_cell *next, void *data)
{
	t_mylist_cell	*cell;

	if ((cell = ft_malloc_s(1, sizeof(*cell))) != NULL)
	{
		cell->v_next = next;
		cell->v_prev = prev;
		cell->v_data = data;
	}
	return (cell);
}

t_mylist_cell			*ft_list_cell_next(const t_mylist_cell *cur)
{
	return (cur->v_next);
}

t_mylist_cell			*ft_list_cell_prev(const t_mylist_cell *cur)
{
	return (cur->v_prev);
}
