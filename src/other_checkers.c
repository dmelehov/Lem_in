/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:25:52 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 19:34:00 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_not_in_queue(t_path *queue, char *s)
{
	while (queue)
	{
		if (ft_strequ(queue->name, s))
			return (0);
		queue = queue->next;
	}
	return (1);
}

int		ft_not_in_ans(t_mylist *lst, char *name)
{
	t_mylist_cell	*begin;

	if (lst->v_size == 0)
		return (1);
	begin = D_LIST(begin)(lst);
	while (begin)
	{
		if (!D_LIST(foreach_if)(begin->v_data, check_name2, name))
			return (0);
		begin = begin->v_next;
	}
	return (1);
}

/*
**	if the strings are equal return false
*/

bool	check_dup_name(void *data, void *s)
{
	if (ft_strequ(((t_node *)data)->name, s))
		return (false);
	return (true);
}

/*
**	if the strings are equal return true
*/

bool	check_name(void *data, void *s)
{
	if (ft_strequ(((t_node *)data)->name, s))
		return (true);
	return (false);
}

/*
**	if the strings are not equal return true
*/

bool	check_name2(void *data, void *s)
{
	if (!ft_strequ(data, s))
		return (true);
	return (false);
}
