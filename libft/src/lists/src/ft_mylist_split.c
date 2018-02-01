/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:32:18 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/25 14:06:57 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static void	ft_list_split_imp(t_mylist *v_this, t_mylist *new_list,
							t_mylist_cell *split_at)
{
	new_list->v_begin = split_at;
	new_list->v_end = D_LIST(end)(v_this);
	new_list->v_size = D_LIST_CELL(count)(split_at, D_LIST(end)(v_this));
	v_this->v_size = D_LIST(size)(v_this) - D_LIST(size)(new_list);
	v_this->v_end = D_LIST_CELL(prev)(split_at);
	v_this->v_end->v_next = NULL;
	new_list->v_begin->v_prev = NULL;
	new_list->v_end->v_next = NULL;
}

void		ft_list_split(t_mylist *v_this, t_mylist_cell *split_at,
						t_mylist *new_list)
{
	if (new_list != NULL && split_at != NULL)
	{
		if (D_LIST(empty)(new_list) == false)
			D_LIST(clear)(new_list);
		if (D_LIST(begin)(v_this) == split_at)
		{
			new_list->v_begin = D_LIST(begin)(v_this);
			new_list->v_end = D_LIST(end)(v_this);
			new_list->v_size = D_LIST(size)(v_this);
			new_list->ft_destroy = v_this->ft_destroy;
			v_this->v_size = 0;
			v_this->v_begin = NULL;
			v_this->v_end = NULL;
			v_this->ft_destroy = NULL;
		}
		else
			D_LIST(split_imp)(v_this, new_list, split_at);
	}
}
