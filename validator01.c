/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:29:51 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/18 20:54:24 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


int     check_num_str(char *line)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (line[i])
    {
        if (ft_isdigit(line[i]))
            i++;
        else
            M_ERROR(-1, "A digit value must be only a positive int");
    }
    res = ft_atoi(line);
    if (res < 1)
    	M_ERROR(-1, "A digit value must be only a positive int");
    return (res);
}

int      ft_get_ants_num(char *line, t_status *status)
{
    status->ant_num = check_num_str(line);
    if (status->ant_num <= 0)
        M_ERROR(-1, "Ant quantity must be a digit only");
    return (1);
}

int     check_delimeters(char const *s, char c)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            res++;
        i++;
    }
    return (res);
}

int     ft_get_room_data(char **arr, t_status *status)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	*node = (t_node){0};
    // if (check_name(node, arr[0]))
    //     error_mngr(9);
    // if (node->name != NULL)
    //     node = get_next_node(node);
    node->name = ft_strdup(arr[0]);
    // printf("!!!!!!!!!!!!!%s\n", node->name);
    node->x = check_num_str(arr[1]);
    node->y = check_num_str(arr[2]);
    printf("!!!%p\n", node);
    D_LIST(push_back)(status->node, node);
    if (status->cur_cmnd == 1)
        status->start = ft_strdup(arr[0]);
    else if (status->cur_cmnd == 2)
        status->end = ft_strdup(arr[0]);
    return (3);
}

int     ft_get_links_data(char *s, t_status *status)
{
    char **arr;
    int  i;

    i = 0;
    if (check_delimeters(s, '-') != 1)
        M_ERROR(-1, "Wrong link format");
    arr = ft_strsplit(s, '-');
    while (arr[i])
        i++;
    if (i != 2)
         M_ERROR(-1, "Wrong link format");
    // if (!check_name(node, arr[0]) || !check_name(node, arr[1]))
    //     M_ERROR(-1, "Wrong link format");
    // get_links(check_name(node, arr[0]), arr[1]);
    // get_links(check_name(node, arr[1]), arr[0]);
    return (5);
}


int     ft_get_input(char *line, t_status *status)
{
    char **s;
    int i;

    i = 0;
    if (status->cur_input_type == 0)
        return (ft_get_ants_num(line, status));
    s = ft_strsplit(line, ' ');
    while (s[i])
        i++;
    if (i == 3 && check_delimeters(line, ' ') != 2)
         M_ERROR(-1, "Wrong room format");
    if (i == 3 && status->cur_input_type <= 3)
        return (ft_get_room_data(s, status));
    else if (i == 1 && status->cur_input_type >= 3)
        return (ft_get_links_data(s[0], status));
    else if (i != 1 && i != 3)
        M_ERROR(-1, "Wrong input format");
    return (0);
}

void     ft_check_status(t_status *status, int inp_type)
{
	if (status->cur_cmnd != 0 && inp_type != 3)
		M_ERROR(-1, "After a command there must be a room");
	if (status->cur_input_type > inp_type)
		M_ERROR(-1, "Wrong input sequence");
	if (inp_type == 5 && !(status->start_exist == 1 && status->end_exist == 1))
		M_ERROR(-1, "Cannot be more than one start or end");
	status->cur_input_type = inp_type;
	status->cur_cmnd = 0;
}

int  ft_check_comand(t_status *status, char *line)
{
	if (line[1] != '#')
		return (0);
	if (ft_strequ(line + 2, "start"))
	{
		if (status->cur_cmnd != 0)
			M_ERROR(-1, "Two valid commands at a stretch");
		if (status->start_exist++ == 0)
			return (1);
		else
			M_ERROR(-1, "One start allready exist");
	}
	else if (ft_strequ(line + 2, "end"))
	{
		if (status->cur_cmnd != 0)
			M_ERROR(-1, "Two valid commands at a stretch");
		if (status->end_exist++ == 0)
			return (2);
		else
			M_ERROR(-1, "One end allready exist");
	}
	return (0);
}

int     ft_validator(t_status *status)
{
	char	*line;
	int		r;

	line = NULL;
	r = 0;
	while ((r = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'L')
			M_ERROR(-1, "Input cannot start with 'L' :(");
		else if (line[0] == '#')
			status->cur_cmnd = ft_check_comand(status, line);
		else if (line[0] == '\0')
			M_ERROR(-1, "Break line on input");
		else
			ft_check_status(status, ft_get_input(line, status));
		printf("%s\n", line);
	}
	printf("\n%-20s%d\n\n","reading return == ", r);
	if (r == -1)
		M_ERROR(-1, "Reading error");
	return (1);
}
