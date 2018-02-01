/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:25:46 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 20:59:02 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

bool			ft_list_foreach_if(t_mylist *v_this,
					bool (*cmp)(void *data, void *value), void *value)
{
	t_mylist_cell	*cur;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		if (cmp(cur->v_data, value) == false)
			return (false);
		cur = cur->v_next;
	}
	return (true);
}

bool			ft_list_foreach(t_mylist *v_this, bool (*funct)(void *data))
{
	t_mylist_cell	*cur;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		if (funct(cur->v_data) == false)
			return (false);
		cur = cur->v_next;
	}
	return (true);
}

void			ft_list_reverse(t_mylist *v_this)
{
	t_mylist_cell	*begin;
	t_mylist_cell	*end;
	void			*tmp;

	end = v_this->v_end;
	begin = v_this->v_begin;
	while (begin != end)
	{
		tmp = begin->v_data;
		begin->v_data = end->v_data;
		end->v_data = tmp;
		if (end->v_prev == begin)
			break ;
		begin = begin->v_next;
		end = end->v_prev;
	}
}

t_mylist_cell	*ft_list_delete(t_mylist *v_this, t_mylist_cell *mb_del)
{
	void			*del;
	t_mylist_cell	*ret;

	ret = D_LIST(erase)(v_this, mb_del, &del);
	v_this->ft_destroy(del);
	return (ret);
}

void			ft_list_delete_if(t_mylist *v_this,
							bool (*cmp)(void *data, void *value), void *value)
{
	t_mylist_cell	*cur;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		if (cmp(cur->v_data, value) == true)
			cur = D_LIST(delete)(v_this, cur);
		else
			cur = cur->v_next;
	}
}
