/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:20:08 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/26 19:01:19 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

bool			ft_list_push_back(t_mylist *v_this, void *data)
{
	t_mylist_cell	*cell;

	cell = D_LIST_CELL(create)(v_this->v_end, NULL, data);
	if (cell == NULL)
	{
		M_ERROR(-1, "Bad alloc");
		return (false);
	}
	if (v_this->v_size == 0)
		v_this->v_begin = cell;
	else
		v_this->v_end->v_next = cell;
	v_this->v_end = cell;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

bool			ft_list_push_front(t_mylist *v_this, void *data)
{
	t_mylist_cell	*cell;

	cell = D_LIST_CELL(create)(NULL, v_this->v_begin, data);
	if (cell == NULL)
	{
		M_ERROR(-1, "Bad alloc");
		return (false);
	}
	if (v_this->v_size == 0)
		v_this->v_end = cell;
	else
		v_this->v_begin->v_prev = cell;
	v_this->v_begin = cell;
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

void			ft_list_pop_back(t_mylist *v_this)
{
	t_mylist_cell	*tmp;

	if (v_this->v_end != NULL)
	{
		v_this->ft_destroy(v_this->v_end->v_data);
		tmp = v_this->v_end->v_prev;
		ft_free_s((void **)&v_this->v_end);
		v_this->v_end = tmp;
		v_this->v_size = v_this->v_size - 1;
		if (v_this->v_end != NULL)
			v_this->v_end->v_next = NULL;
		else
			v_this->v_begin = NULL;
	}
}

void			ft_list_pop_front(t_mylist *v_this)
{
	t_mylist_cell	*tmp;

	if (v_this->v_begin != NULL)
	{
		v_this->ft_destroy(v_this->v_begin->v_data);
		tmp = v_this->v_begin->v_next;
		ft_free_s((void **)&v_this->v_begin);
		v_this->v_begin = tmp;
		v_this->v_size = v_this->v_size - 1;
		if (v_this->v_begin != NULL)
			v_this->v_begin->v_prev = NULL;
		else
			v_this->v_end = NULL;
	}
}

t_mylist_cell	*ft_list_erase(t_mylist *v_this,
				t_mylist_cell *erase, void **data)
{
	t_mylist_cell	*ret;

	ret = erase->v_next;
	if (data != NULL)
		*data = erase->v_data;
	if (erase == v_this->v_begin)
		v_this->v_begin = ret;
	else if (erase == v_this->v_end)
		v_this->v_end = erase->v_prev;
	if (erase->v_prev != NULL)
		erase->v_prev->v_next = erase->v_next;
	if (erase->v_next != NULL)
		erase->v_next->v_prev = erase->v_prev;
	ft_free_s((void **)&erase);
	v_this->v_size = v_this->v_size - 1;
	if (v_this->v_size == 0)
	{
		v_this->v_begin = NULL;
		v_this->v_end = NULL;
	}
	return (ret);
}
