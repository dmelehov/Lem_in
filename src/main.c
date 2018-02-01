/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:34:07 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 21:00:18 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		set_max_path_qtty(t_status *status)
{
	int	max_start_links;
	int	max_end_links;
	int	max_posbl_paths;

	max_start_links = ((t_array *)((t_node *)((D_LIST(find)(status->node,
		check_name, status->start)))->v_data)->link)->v_size;
	max_end_links = ((t_array *)((t_node *)((D_LIST(find)(status->node,
		check_name, status->end)))->v_data)->link)->v_size;
	max_posbl_paths = (max_start_links >=
		max_end_links ? max_end_links : max_start_links);
	if (status->ant_num < max_posbl_paths)
		status->max_path_num = status->ant_num;
	else
		status->max_path_num = max_posbl_paths;
}

static t_path	*get_another_path(t_mylist_cell *lst, t_path *lst2)
{
	lst2 = (t_path*)ft_malloc_s(1, sizeof(t_path));
	*lst2 = (t_path){lst->v_data, NULL, NULL, NULL};
	if (lst->v_next)
		lst2->next = get_another_path(lst->v_next, lst2->next);
	return (lst2);
}

static t_path	*set_toprint_list(t_mylist_cell *lst, t_path *lst2)
{
	t_path *ans;

	ans = get_another_path(D_LIST(begin)(lst->v_data), NULL);
	lst = lst->v_next;
	lst2 = ans;
	while (lst)
	{
		lst2->ways = get_another_path(D_LIST(begin)(lst->v_data), NULL);
		lst2 = lst2->ways;
		lst = lst->v_next;
	}
	return (ans);
}

static t_status	*ft_init_main_struct(t_status *status)
{
	status = (t_status *)ft_malloc_s(1, sizeof(t_status));
	*status = (t_status)STATUS;
	status->node = (t_mylist *)ft_malloc_s(1, sizeof(t_mylist));
	D_LIST(init)(status->node, NULL);
	status->output = (t_array *)ft_malloc_s(1, sizeof(t_array));
	D_ARRAY(init)(status->output, NULL, NULL, sizeof(t_array));
	status->ans = (t_mylist *)ft_malloc_s(1, sizeof(t_mylist));
	D_LIST(init)(status->ans, NULL);
	return (status);
}

int				main(int ac, char **av)
{
	t_status	*status;

	status = ft_init_main_struct(NULL);
	flag_seter(status, ac, ft_strtrim(av[1]));
	ft_validator(status, 0);
	set_max_path_qtty(status);
	if (ERC > 0 && status->quiet == 0)
		ft_print_status_struct(status);
	ft_bfs_solution(status);
	check_path_presence(status);
	if (status->quiet == 0)
	{
		D_ARRAY(foreach)(status->output, ft_print_output);
		ft_printf("\n");
	}
	status->toprint = set_toprint_list(D_LIST(begin)(status->ans), NULL);
	if (status->pr_mult == 0)
		optimize_paths(status);
	if (status->pr_paths > 0)
		ft_print_found_paths(status->toprint);
	ft_print_answer(status);
	ft_memory_liberator(status);
	return (0);
}
