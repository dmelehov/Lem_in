/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_other_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:55:11 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/01 12:52:54 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	set_path_unavailible(t_path *path, char *end)
{
	while (path)
	{
		path->from = end;
		path = path->next;
	}
}

static int	find_path_len(t_path *path)
{
	int	i;

	i = 0;
	while (path)
	{
		path = path->next;
		i++;
	}
	return (i);
}

void		optimize_paths(t_status *status)
{
	t_path	*path;
	int		path_len;

	path = status->toprint;
	path_len = find_path_len(path);
	while (path->ways)
	{
		path = path->ways;
		if (path_len < find_path_len(path))
			set_path_unavailible(path, status->end);
	}
}

void		check_path_presence(t_status *status)
{
	if ((D_LIST(size)(status->ans)) == 0)
		D_ERROR(ERC, "No availible path was found");
}

void		check_struct_fullness(t_status *status)
{
	t_node	*cur;

	cur = NULL;
	if (status->cur_input_type != 5)
		D_ERROR(ERC, "No links on input");
	cur = (D_LIST(find)(status->node, check_name, status->end))->v_data;
	if (cur->link == NULL)
		D_ERROR(ERC, "No links with end");
	cur = (D_LIST(find)(status->node, check_name, status->start))->v_data;
	if (cur->link == NULL)
		D_ERROR(ERC, "No links with start");
	
}
