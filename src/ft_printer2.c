/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:33:20 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 19:01:11 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_napominalka(void)
{
	ft_printf("%-20s%zu\n", "t_mylist", sizeof(t_mylist));
	ft_printf("%-20s%zu\n", "t_mylist_cell", sizeof(t_mylist_cell));
	ft_printf("%-20s%zu\n", "t_node", sizeof(t_node));
	ft_printf("%-20s%zu\n", "t_status", sizeof(t_status));
	ft_printf("%-20s%zu\n", "t_path", sizeof(t_path));
}

bool	ft_print_node(void *data)
{
	char *s;

	s = NULL;
	ft_printf("[%s]  ", ((t_node *)data)->name);
	ft_printf("%d  ", ((t_node *)data)->x);
	ft_printf("%d\n", ((t_node *)data)->y);
	D_ARRAY(foreach)(((t_node *)data)->link, ft_print_links);
	ft_printf("\n");
	return (true);
}

void	ft_print_queue(t_path *queue)
{
	while (queue)
	{
		ft_printf("--{%s|%s}", queue->name, queue->from);
		queue = queue->next;
	}
	ft_printf("\n--------------\n");
}

bool	ft_print_links(void *data)
{
	ft_printf("--{%s}", (char *)data);
	return (true);
}

bool	ft_print_visited(void *data)
{
	ft_printf("--[%s]", (char *)data);
	return (true);
}
