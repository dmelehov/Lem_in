/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:07:26 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/31 20:26:09 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** создание массивов цветов
*/

static char	const	*ft_match_color(char const *s, int i, int path)
{
	char const	*colors[] = {"{red}", "{green}", "{yellow}", "{blue}",
	"{magenta}", "{cyan}", "{white}", "{black}", "{red|b}", "{green|b}",
	"{yellow|b}", "{blue|b}", "{magenta|b}", "{cyan|b}", "{white|b}",
	"{black|b}", "{eoc}", NULL};
	char const	*codes[] = {"\x1b[31m", "\x1b[32m", "\x1b[33m", "\x1b[34m",
	"\x1b[35m", "\x1b[36m", "\x1b[37m", "\x1b[30m", "\x1b[41m", "\x1b[42m",
	"\x1b[43m", "\x1b[44m", "\x1b[45m", "\x1b[46m", "\x1b[47m",
	"\x1b[40m", "\x1b[0m", NULL};

	while (path == 1 && colors[i])
	{
		if (!ft_strncmp(s, colors[i], ft_strlen(colors[i])))
			return (codes[i]);
		i++;
	}
	while (path == 2 && codes[i])
	{
		if (!ft_strncmp(s, codes[i], ft_strlen(codes[i])))
			return (colors[i]);
		i++;
	}
	return (NULL);
}

/*
** проверка наличия цвета и его применение
*/

int					ft_check_color(char *format, char **s, int *ans)
{
	char const	*code;
	int			i;

	code = ft_match_color(format, 0, 1);
	i = 0;
	if (code == NULL)
		return (0);
	while (code[i] != '\0')
		(*s)[(*ans)++] = code[i++];
	code = ft_match_color(code, 0, 2);
	return (ft_strlen(code));
}

void				ft_free_struct(t_argdata *data)
{
	ft_strdel(&(data->form_input));
	ft_memdel((void **)&data);
}
