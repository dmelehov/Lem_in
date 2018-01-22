/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylist_splice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:30:38 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 20:57:13 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static void		ft_list_pick_cells_imp(t_mylist *const v_this,
									t_mylist_cell *const begin,
									t_mylist_cell *const end)
{
	t_mylist_cell	*cell_before;
	t_mylist_cell	*cell_after;

	cell_before = D_LIST_CELL(prev)(begin);
	cell_after = D_LIST_CELL(next)(end);
	if (cell_before == NULL)
	{
		v_this->v_begin = cell_after;
		if (cell_after != NULL)
			cell_after->v_prev = NULL;
	}
	else
		cell_before->v_next = cell_after;
	if (cell_after == NULL)
	{
		if (D_LIST(begin)(v_this) != NULL)
			v_this->v_end = D_LIST_CELL(next)(v_this->v_begin);
		else
			v_this->v_end = D_LIST(begin)(v_this);
	}
	else
		cell_after->v_prev = cell_before;
}

static size_t	ft_list_pick_cells(t_mylist *const v_this,
								t_mylist_cell *const begin, t_mylist_cell *end)
{
	size_t	cell_count;

	if (D_LIST(empty)(v_this) == true)
		return (0);
	if (end == NULL)
		end = D_LIST(end)(v_this);
	cell_count = D_LIST_CELL(count)(begin, end);
	D_LIST(pick_cells_imp)(v_this, begin, end);
	v_this->v_size = D_LIST(size)(v_this) - cell_count;
	begin->v_prev = NULL;
	end->v_next = NULL;
	return (cell_count);
}

static void		ft_list_splice_imp(t_mylist *const v_this,
								t_mylist_cell *const position,
								t_mylist_cell *const other_begin,
								t_mylist_cell *const other_end)
{
	t_mylist_cell	*before;

	before = D_LIST_CELL(prev)(position);
	if (before == NULL)
	{
		v_this->v_begin = other_begin;
		v_this->v_begin->v_prev = NULL;
	}
	else
	{
		before->v_next = other_begin;
		other_begin->v_prev = before;
	}
	position->v_prev = other_end;
	other_end->v_next = position;
}

void			ft_list_splice(t_mylist *v_this, t_mylist_cell *position,
							t_mylist *other_list,
							t_mylist_interval *other_interval)
{
	size_t	cell_count;

	cell_count = D_LIST(pick_cells)(other_list,
									D_LIST_INTERVAL(begin)(other_interval),
									D_LIST_INTERVAL(end)(other_interval));
	if (cell_count == 0)
		return ;
	if (D_LIST(empty)(v_this) == true)
	{
		v_this->v_size = cell_count;
		v_this->v_begin = D_LIST_INTERVAL(begin)(other_interval);
		v_this->v_end = D_LIST_INTERVAL(end)(other_interval);
		return ;
	}
	if (position == NULL)
	{
		position = D_LIST(end)(v_this);
		position->v_next = D_LIST_INTERVAL(begin)(other_interval);
		D_LIST_INTERVAL(begin)(other_interval)->v_prev = position;
	}
	else
		D_LIST(splice_imp)(v_this, position,
						D_LIST_INTERVAL(begin)(other_interval),
						D_LIST_INTERVAL(end)(other_interval));
	v_this->v_size = D_LIST(size)(v_this) + cell_count;
}
