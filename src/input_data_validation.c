/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:09:14 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 18:49:35 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_get_input(char *line, t_status *status)
{
	char	**s;
	int		i;

	i = 0;
	if (status->cur_input_type == 0)
		return (ft_get_ants_num(line, status));
	s = ft_strsplit(line, ' ');
	while (s[i])
		i++;
	if (i == 3 && check_delimeters(line, ' ') != 2)
		D_ERROR(ERC, "Wrong room format");
	if (i == 3 && status->cur_input_type <= 3)
		return (ft_get_room_data(s, status));
	else if (i == 1 && status->cur_input_type >= 3)
		return (ft_get_links_data(s, status));
	else if (i != 1 && i != 3)
		D_ERROR(ERC, "Wrong input format");
	ft_free_2d_array((void**)s);
	return (0);
}

void	ft_check_status(t_status *status, int inp_type)
{
	if (status->cur_cmnd != 0 && inp_type != 3)
		D_ERROR(ERC, "After a command there must be a room");
	if (status->cur_input_type > inp_type)
		D_ERROR(ERC, "Wrong input sequence");
	if (inp_type == 5 && !(status->start_exist == 1 && status->end_exist == 1))
		D_ERROR(ERC, "Cannot be more than one start or end");
	status->cur_input_type = inp_type;
	status->cur_cmnd = 0;
}

int		ft_check_comand(t_status *status, char *line)
{
	if (ft_strlen(line) < 2 || line[1] != '#')
		return (status->cur_cmnd);
	if (ft_strequ(line + 2, "start"))
	{
		if (status->cur_cmnd != 0)
			D_ERROR(ERC, "Two valid commands at a stretch");
		if (status->start_exist++ == 0)
			return (1);
		else
			D_ERROR(ERC, "One start allready exist");
	}
	else if (ft_strequ(line + 2, "end"))
	{
		if (status->cur_cmnd != 0)
			D_ERROR(ERC, "Two valid commands at a stretch");
		if (status->end_exist++ == 0)
			return (2);
		else
			D_ERROR(ERC, "One end allready exist");
	}
	return (status->cur_cmnd);
}

int		ft_validator(t_status *status, int ret)
{
	char	*line;

	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'L')
			D_ERROR(ERC, "Input cannot start with 'L' :(");
		else if (line[0] == '#')
			status->cur_cmnd = ft_check_comand(status, line);
		else if (line[0] == '\0')
			D_ERROR(ERC, "Break line on input");
		else
			ft_check_status(status, ft_get_input(line, status));
		D_ARRAY(push_back)(status->output, line);
		ft_strdel(&line);
	}
	if (ret == -1)
		D_ERROR(ERC, "Reading error");
	check_struct_fullness(status);
	ft_strdel(&line);
	return (1);
}
