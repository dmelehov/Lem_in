/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getters_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:29:51 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 11:34:15 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

#define SKIPCHAR "0\t\v\n\r\f "

int					ft_get_ants_num(char *line, t_status *status)
{
	while (ft_strchr(SKIPCHAR, (*line)))
		line++;
	status->ant_num = check_num_str(line, ERC);
	if (status->ant_num <= 0)
		D_ERROR(ERC, "Ant quantity must be an integer only");
	return (1);
}

int					ft_get_room_data(char **arr, t_status *status)
{
	t_node	*node;
	int		crdts[2];

	node = (t_node *)malloc(sizeof(*node));
	*node = (t_node){NULL, 0, 0, NULL};
	crdts[0] = check_num_str(arr[1], ERC);
	crdts[1] = check_num_str(arr[2], ERC);
	if (!(D_LIST(foreach_if)(status->node, check_dup_name, arr[0])))
		D_ERROR(ERC, "Duplicated room name");
	if (!(D_LIST(foreach_if)(status->node, check_cordinates, crdts)))
		D_ERROR(ERC, "Duplicated cordinates");
	*node = (t_node){ft_strdup(arr[0]), crdts[0], crdts[1], NULL};
	D_LIST(push_back)(status->node, node);
	if (status->cur_cmnd == 1)
		status->start = ft_strdup(arr[0]);
	else if (status->cur_cmnd == 2)
		status->end = ft_strdup(arr[0]);
	ft_free_2d_array((void**)arr);
	return (3);
}

void				ft_add_a_link(t_status *status, char *from, char *to)
{
	t_mylist_cell	*lst;

	lst = NULL;
	if (!(lst = D_LIST(find)(status->node, check_name, from)))
		D_ERROR(ERC, "Padstava!!!No room with name from link");
	if (((t_node *)lst->v_data)->link == NULL)
	{
		((t_node *)lst->v_data)->link = (t_array *)malloc(sizeof(t_array));
		D_ARRAY(init)(((t_node *)lst->v_data)->link,
			NULL, NULL, sizeof(t_array));
	}
	else if (!D_ARRAY(foreach_if)(((t_node *)lst->v_data)->link,
			check_name2, to))
		D_ERROR(ERC, "Duplicated links");
	D_ARRAY(push_back)(((t_node *)lst->v_data)->link, to);
}

int					ft_get_links_data(char **s, t_status *status)
{
	char	**arr;
	int		i;

	i = 0;
	if (check_delimeters(s[0], '-') != 1)
		D_ERROR(ERC, "Wrong link formating");
	arr = ft_strsplit(s[0], '-');
	while (arr[i])
		i++;
	if (i != 2)
		D_ERROR(ERC, "Wrong link input type");
	if (D_LIST(foreach_if)(status->node, check_dup_name, arr[0])
		|| D_LIST(foreach_if)(status->node, check_dup_name, arr[1]))
		D_ERROR(ERC, "Linking with invalid room name");
	ft_add_a_link(status, arr[0], arr[1]);
	ft_add_a_link(status, arr[1], arr[0]);
	ft_free_2d_array((void**)arr);
	ft_free_2d_array((void**)s);
	return (5);
}

#undef SKIPCHAR
