/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:47:10 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 21:01:22 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_print_status_struct(t_status *data)
{
	ft_printf("{blue}");
	ft_printf("%-20s%zu\n", "struct size == ", sizeof(*data));
	ft_printf("%-20s%d\n", "ant_num == ", data->ant_num);
	ft_printf("%-20s%d\n", "start_exist == ", data->start_exist);
	ft_printf("%-20s%d\n", "end_exist == ", data->end_exist);
	ft_printf("%-20s%d\n", "cur_cmnd == ", data->cur_cmnd);
	ft_printf("%-20s%d\n", "cur_input_type == ", data->cur_input_type);
	ft_printf("%-20s%d\n", "max_path_num == ", data->max_path_num);
	ft_printf("%-20s%s\n", "start name == ", data->start);
	ft_printf("%-20s%s\n", "end name == ", data->end);
	ft_printf("%-20s%d\n", "flag debug == ", data->debug);
	ft_printf("%-20s%d\n", "flag path == ", data->pr_paths);
	ft_printf("%-20s%d\n", "flag mult == ", data->pr_mult);
	ft_printf("%-20s%d\n", "flag quiet == ", data->quiet);
	ft_printf("%-20s%p\n", "node addr == ", data->node);
	ft_printf("%-20s%p\n", "output addr == ", data->output);
	ft_printf("%-20s%p\n", "ans addr == ", data->ans);
	ft_printf("%-20s%p\n", "ants addr == ", data->ants);
	ft_printf("%-20s%p\n", "toprint addr == ", data->toprint);
	ft_printf("{eoc}");
}

void	ft_print_found_paths(t_path *path)
{
	t_path *lst;

	lst = path;
	while (path)
	{
		lst = path;
		while (lst)
		{
			ft_printf("{green}");
			ft_printf("{%s}", lst->name);
			if (lst->next)
				ft_printf("%s", "--");
			lst = lst->next;
		}
		ft_printf("{eoc}");
		ft_printf("\n");
		path = path->ways;
	}
	ft_printf("\n");
}

bool	ft_print_paths(void *data)
{
	t_array *arr;

	arr = data;
	D_ARRAY(foreach)(arr, ft_print_visited);
	ft_printf("\n");
	return (true);
}

bool	ft_print_output(void *data)
{
	ft_printf("{magenta}");
	ft_printf("%s{eoc}\n", (char *)data);
	return (true);
}

bool	print_solution(void *ans)
{
	static int i = 1;

	ft_printf("Path number {%d}:\n", i++);
	D_LIST(foreach)(ans, ft_print_visited);
	ft_printf("\n");
	return (true);
}
