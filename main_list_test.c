/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:34:07 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/20 15:24:18 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "lemin.h"
#include <malloc/malloc.h>
#include <sys/types.h>
#include <sys/sysctl.h>

void	ft_print_status_struct(t_status *data)
{
	printf("%-20s%zu\n","struct size == ", sizeof(*data));
	printf("%-20s%d\n", "ant_num == ", data->ant_num);
	printf("%-20s%d\n", "start_exist == ", data->start_exist);
	printf("%-20s%d\n", "end_exist == ", data->end_exist);
	printf("%-20s%d\n", "cur_cmnd == ", data->cur_cmnd);
	printf("%-20s%d\n", "cur_input_type == ", data->cur_input_type);
	printf("%-20s%s\n", "start name == ", data->start);
	printf("%-20s%s\n", "end name == ", data->end);
	printf("%-20s%p\n", "ans addr == ", data->ans);
	printf("%-20s%p\n", "node addr == ", data->node);
}

// bool	ft_print_data(void *data)
// {
// 	printf("Data = %zu\n", (size_t)data);
// 	// printf("%s\n", ((t_path *)data)->name);
// 	// printf("%s\n", ((t_path *)data)->from);
// 	return (true);
// }

bool	ft_print_node(void *data)
{
	printf("%s  ", ((t_node *)data)->name);
	printf("%d  ", ((t_node *)data)->x);
	printf("%d\n", ((t_node *)data)->y);
	return (true);
}





int		main(int argc, char const** argv)
{
	t_status	status;
	t_mylist	*rooms;

	rooms = (t_mylist *)ft_malloc_s(1, sizeof(*rooms));
	D_LIST(init)(rooms, NULL);
	status = (t_status){0};
	status.node = rooms;
	if (ft_validator(&status) == 0)
		M_ERROR(-1, "ERROR_NAH");
	ft_print_status_struct(&status);

	// printf("[%s]\n", ((t_node *)(status.node->v_end->v_data))->name);
	// printf("[%p]\n", (t_node *)(status.node->v_end));
	// printf("[%zu]\n", status.node->v_size);
	
	D_LIST(foreach)(status.node, ft_print_node);
	// t_path		path;

	/*
	 * Initialize with delete pointer NULL because my data it's not allocated
	 */

	// D_LIST(init)(&list, NULL);
	/*
	 * Push at the end, the data 101
	 * Check return Value ?
	 * No it's useless ! Ok Master
	 */
	// path = (t_path){"SRAV", "HUJ", NULL, NULL};
	// D_LIST(push_back)(&list, (void *)(&path));
	// path = (t_path){"EBAV", "LEMIN", NULL, NULL};
	// D_LIST(push_back)(&list, (void *)(&path));
	// D_LIST(push_back)(&list, (void *)101);
	// D_LIST(push_back)(&list, (void *)11101);
	// D_LIST(push_back)(&list, (void *)666);
	// D_LIST(push_back)(&list, (void *)13);
	// D_LIST(foreach)(&list, ft_print_data);
	// ft_print_data(list.)
	/*
	 * We free memory ?
	 * Well ... let it and we'll see
	 */
	// D_LIST(destroy)(&list);
	(void)argc;
	(void)argv;
	return (0);
}
