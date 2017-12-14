/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:11:14 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/17 06:24:44 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	int		ft_checker(t_line **new, int const fd)
{
	if (*new == NULL)
	{
		*new = (t_line *)malloc(sizeof(t_line));
		(*new)->rfd = fd;
		(*new)->next = NULL;
		if (!((*new)->cache = ft_strnew(1)))
			return (-1);
	}
	if (fd < 0 || BUFF_SIZE < 1 || BUFF_SIZE > MAX_INT)
		return (-1);
	if (!((*new)->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	return (0);
}

static	int		ft_gnlwriter(t_line **new, char **line, int path)
{
	if (path == 1)
	{
		*line = ft_strsub((*new)->cache, 0,
			ft_strchr((*new)->cache, '\n') - (*new)->cache);
		(*new)->temp = (*new)->cache;
		(*new)->cache = ft_strsub((*new)->cache, ft_strchr((*new)->cache, '\n')
			- (*new)->cache + 1, ft_strlen((*new)->cache));
		ft_strdel(&((*new)->temp));
		return (1);
	}
	if (path == 2)
	{
		*line = ft_strjoin((*new)->cache, (ft_strsub((*new)->buff, 0,
			ft_strchr((*new)->buff, '\n') - (*new)->buff)));
		(*new)->temp = (*new)->cache;
		(*new)->cache = ft_strsub((*new)->buff, ft_strchr((*new)->buff, '\n')
			- (*new)->buff + 1, ft_strlen((*new)->buff));
		ft_strdel(&((*new)->temp));
	}
	return (0);
}

static	int		ft_gnlreader(t_line **new, int const fd, char **line)
{
	int		r;

	if (ft_strchr((*new)->cache, '\n') && (ft_gnlwriter(new, line, 1) == 1))
		return (1);
	while (((r = read(fd, (*new)->buff, BUFF_SIZE)) > 0)
		&& !(ft_strchr((*new)->buff, '\n')))
	{
		(*new)->buff[r] = '\0';
		(*new)->temp = (*new)->cache;
		(*new)->cache = ft_strjoin((*new)->cache, (*new)->buff);
		ft_strdel(&((*new)->temp));
	}
	if (r < 0)
		return (-1);
	(*new)->buff[r] = '\0';
	if (r < BUFF_SIZE && (*new)->buff[r - 1] != '\n')
	{
		(*new)->buff[r] = '\n';
		(*new)->buff[r + 1] = '\0';
	}
	if (ft_strchr((*new)->buff, '\n') != NULL)
		ft_gnlwriter(new, line, 2);
	if (r == 0 && ft_strcmp(*line, (*new)->cache) == 0)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	t_line	*base;
	t_line			*new;

	if (base == NULL)
	{
		if (ft_checker(&base, fd) != 0)
			return (-1);
		new = base;
	}
	else
	{
		new = base;
		while (new->next != NULL && fd != new->rfd)
			new = new->next;
		if (fd != new->rfd)
		{
			if (ft_checker(&(new->next), fd) != 0)
				return (-1);
			new = new->next;
		}
	}
	return (ft_gnlreader(&new, fd, line));
}
