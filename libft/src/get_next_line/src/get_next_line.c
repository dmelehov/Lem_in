/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:11:14 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/16 16:30:36 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../includes/get_next_line.h"

#define BUFF (char *)lst->content
#define POS ft_strchr((char *)lst->content, '\n')

static	int		ft_append(char **line, t_list *lst)
{
	char	*tmp;

	tmp = NULL;
	if (*line == NULL)
		*line = ft_strdup(BUFF);
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, BUFF);
		ft_strdel(&tmp);
	}
	if (POS)
	{
		ft_strclr(ft_strchr(*line, '\n'));
		tmp = ft_strdup(POS + 1);
		ft_bzero(BUFF, BUFF_SIZE);
		ft_strcpy(lst->content, tmp);
		ft_strdel(&tmp);
	}
	else
		ft_bzero(BUFF, BUFF_SIZE);
	return (ft_strlen(*line));
}

static	int		ft_reader(const int fd, char **line, t_list *lst)
{
	int	r;

	r = 0;
	if ((BUFF)[0] != '\0' && POS)
		return (ft_append(line, lst) >= 0 ? 1 : 0);
	else if ((BUFF)[0] != '\0')
		ft_append(line, lst);
	while (!POS && (r = read(fd, BUFF, BUFF_SIZE)) > 0)
	{
		if (POS)
			break ;
		ft_append(line, lst);
		ft_bzero(BUFF, BUFF_SIZE);
	}
	if (r < 0)
		return (-1);
	r += ft_append(line, lst);
	return (r > 0 ? 1 : 0);
}

static	int		ft_get_elem(t_list **new, int const fd)
{
	if (!(*new = ft_lstnew(NULL, 0)))
		return (-1);
	if (!((*new)->content = ft_strnew(BUFF_SIZE)))
		return (-1);
	(*new)->content_size = fd;
	(*new)->next = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*lst;
	t_list			*new;

	if (fd < 0 || BUFF_SIZE < 1 || BUFF_SIZE > MAX_INT || line == NULL)
		return (-1);
	*line = NULL;
	if (lst == NULL)
	{
		if (ft_get_elem(&lst, fd) == -1)
			return (-1);
		new = lst;
	}
	else
	{
		new = lst;
		while (new->next && fd != (int)new->content_size)
			new = new->next;
		if (fd != (int)new->content_size)
		{
			if (ft_get_elem(&(new->next), fd) == -1)
				return (-1);
			new = new->next;
		}
	}
	return (ft_reader(fd, line, new));
}

#undef BUFF
#undef POS
