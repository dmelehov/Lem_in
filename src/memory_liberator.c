/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_liberator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:57:53 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 15:52:09 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		set_antlist_free(t_path *antlist)
{
	ft_strdel(&(antlist->name));
	if (antlist->next)
		set_antlist_free(antlist->next);
	ft_free_s((void **)&antlist);
}

static void		set_free_toprint(t_path *path)
{
	if (path->ways)
		set_free_toprint(path->ways);
	set_queue_free(path);
}

static bool		ft_free_ans(void *data)
{
	D_LIST(destroy)(data);
	ft_free_s(&data);
	return (true);
}

static bool		ft_free_node(void *lst)
{
	ft_strdel(&(((t_node *)lst)->name));
	if (((t_node *)lst)->link)
	{
		D_ARRAY(destroy)(((t_node *)lst)->link);
		ft_free_s((void **)&(((t_node *)lst)->link));
	}
	ft_free_s(&lst);
	return (true);
}

void			ft_memory_liberator(t_status *status)
{
	ft_strdel(&status->start);
	ft_strdel(&status->end);
	D_LIST(foreach)(status->node, ft_free_node);
	D_LIST(destroy)(status->node);
	ft_free_s((void **)(&(status->node)));
	D_ARRAY(destroy)(status->output);
	ft_free_s((void **)(&(status->output)));
	D_LIST(foreach)(status->ans, ft_free_ans);
	D_LIST(destroy)(status->ans);
	ft_free_s((void **)(&(status->ans)));
	set_antlist_free(status->ants);
	status->ants = NULL;
	set_free_toprint(status->toprint);
	status->toprint = NULL;
	ft_free_s((void**)&status);
}
