/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatparsing_additional.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:58 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/16 22:23:04 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** дополнительные функции парсинга, применения флагов и обработки нулевых чаров
*/

/*
** обработка нулевых чаровых знаений
*/

void		ft_nullcharprint(char *str, t_argdata *data, char **s)
{
	int i;

	i = 0;
	str = ft_strnew(1);
	if (data->minus)
		(*s)[(data->ans)++] = str[i];
	str = ft_apply_modifyers(str, data);
	if (ft_strlen(str) != 0)
		str[ft_strlen(str) - 1] = '\0';
	while (str[i])
		(*s)[(data->ans)++] = str[i++];
	if (!data->minus)
		(*s)[(data->ans)++] = str[i];
}

/*
** поиск границы значущих модификаторов в строке аргумента
*/

char		*ft_getformat(char *format, t_argdata *data)
{
	int i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
	{
		if (ft_isascii(format[i]) && !(ft_strchr(RESERVED, format[i])))
			break ;
		if ((ft_isalpha(format[i]) == 1) && (ft_strchr(CONVERT, format[i])))
			break ;
		i++;
	}
	if (format[i] != '\0')
		data->form_input = ft_strsub(format, 0, i + 1);
	else if (format[i] == '\0')
		data->form_input = ft_strsub(format, 0, i);
	ft_fillstruct(data);
	if (format[i] == '\0')
		return (format + i);
	return (format + i + 1);
}

/*
** создание структуры для записи модификаторов аргумента
*/

t_argdata	*ft_get_argdata(t_argdata *data, char *format, int argnum, int ans)
{
	data = (t_argdata *)malloc(sizeof(t_argdata));
	*data = (t_argdata)NRG;
	data->arg_num = argnum;
	data->ans = ans;
	ft_getformat(format + 1, data);
	return (data);
}

/*
** получение значения флага звезды
*/

int			ft_getstarvalue(va_list *ap, t_argdata *data)
{
	int i;

	i = va_arg(*ap, int);
	if (i < 0)
	{
		i = -i;
		data->minus = '-';
	}
	return (i);
}

/*
** применение флага звезды
*/

void		ft_apply_star(va_list *ap, t_argdata *data)
{
	int		i;
	char	*s;

	s = data->form_input;
	while (*s)
	{
		if (s[0] == '.' && s[1] == '*')
		{
			i = ft_getstarvalue(ap, data);
			if (i > data->size && data->minus)
				i = data->size;
			s += 2;
			if (data->precision == -1 || data->precision == 0)
				data->precision = i;
		}
		if (s[0] == '*')
		{
			i = ft_getstarvalue(ap, data);
			if (data->size == -1 || ft_nonums_after(s) == 1)
				data->size = i;
		}
		s++;
	}
}
