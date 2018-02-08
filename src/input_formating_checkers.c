/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_formating_checkers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:24:18 by dmelehov          #+#    #+#             */
/*   Updated: 2018/02/08 11:26:17 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	set_queue_free(t_path *queue)
{
	if (queue->next)
		set_queue_free(queue->next);
	ft_free_s((void **)&queue);
}

int		check_delimeters(char const *s, char c)
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

int		check_num_str(char *line, int erc)
{
	int			i;
	int			res;
	intmax_t	t;

	i = 0;
	res = 0;
	if (ft_strlen(line) > 10)
		D_ERROR(erc, "Ant quantity must be an integer only");
	t = ft_latoi(line);
	if (t >= 2147483647)
		D_ERROR(erc, "Ant quantity must be an integer only");
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else
			D_ERROR(erc, "A digit value must be only a positive int");
	}
	res = ft_atoi(line);
	if (res < 1 && line[0] != '0')
		D_ERROR(erc, "A digit value must be only a positive int");
	return (res);
}

bool	check_cordinates(void *data, void *dot)
{
	if (((t_node *)data)->x == ((int *)dot)[0]
		&& ((t_node *)data)->y == ((int *)dot)[1])
		return (false);
	return (true);
}

char	*get_next_path_elem(t_path *queue, char *s)
{
	while (queue && !ft_strequ(queue->name, s))
		queue = queue->next;
	return (queue->from);
}
