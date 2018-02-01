/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:38:07 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 14:50:12 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		add_to_queue(t_path *queue, char *s, char *from)
{
	t_path	*new;

	new = NULL;
	if (!queue)
		return ;
	while (queue->next)
		queue = queue->next;
	queue->next = (t_path *)ft_malloc_s(1, sizeof(t_path));
	*(queue->next) = (t_path){s, from, NULL, queue};
}

static int		add_to_ans(t_status *status, t_path *queue, char *cur)
{
	t_mylist	*ans;
	t_path		*begin;
	char		*s;

	begin = queue;
	ans = (t_mylist *)ft_malloc_s(1, sizeof(t_mylist));
	D_LIST(init)(ans, NULL);
	while (begin->next)
		begin = begin->next;
	s = cur;
	while (s)
	{
		D_LIST(push_front)(ans, s);
		s = get_next_path_elem(queue, s);
	}
	D_LIST(push_back)(ans, status->end);
	D_LIST(push_back)(status->ans, ans);
	return (1);
}

static int		add_childs_to_queue(t_status *status,
	t_node *current, t_path *queue)
{
	size_t	size;
	size_t	i;
	char	*s;

	size = D_ARRAY(size)(current->link);
	i = 0;
	while (i < size)
	{
		s = F_ARRAY_AT(current->link, i, char *);
		if (ft_strequ(status->end, s))
			return (add_to_ans(status, queue, current->name));
		if (ft_not_in_queue(queue, s) && ft_not_in_ans(status->ans, s))
			add_to_queue(queue, s, current->name);
		i++;
	}
	return (0);
}

static void		bfs(t_status *status, t_path *queue)
{
	t_path	*begin;
	t_node	*cur;

	begin = queue;
	queue->name = status->start;
	queue->from = NULL;
	while (begin)
	{
		cur = ((t_node *)(D_LIST(find)(status->node,
			check_name, begin->name))->v_data);
		if (add_childs_to_queue(status, cur, queue))
			return ;
		begin = begin->next;
	}
}

void			ft_bfs_solution(t_status *status)
{
	t_path			*queue;
	t_mylist_cell	*cell;
	int				cycles;

	cycles = status->max_path_num;
	while (cycles--)
	{
		queue = (t_path *)ft_malloc_s(1, sizeof(t_path));
		*queue = (t_path){NULL, NULL, NULL, NULL};
		cell = D_LIST(find)(status->node, check_name, status->start);
		bfs(status, queue);
		set_queue_free(queue);
	}
}
