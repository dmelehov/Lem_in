/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:39:19 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/11 14:54:34 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** определение точности
*/

int		ft_updateprecision(char *s)
{
	while (ft_strchr(s, '.'))
	{
		s = ft_strchr(s, '.');
		s++;
	}
	if (ft_isdigit(s[0]) == 1)
		return (ft_atoi(s));
	else
		return (0);
}

/*
** определение длинны
*/

char	*ft_updatelenght(char *s, t_argdata *data)
{
	if ((ft_strchr(LENGHT, s[1])) && ((ft_strchr(CONVERT, s[2]) ||
		(ft_strchr(FLAGS, s[2])))))
	{
		if (s[0] == s[1])
			data->lenght = ft_toupper(s[0]);
		else
			data->lenght = s[0];
		return (s + 2);
	}
	if ((ft_strchr(LENGHT, s[0])) && (ft_strchr(CONVERT, s[1])))
	{
		if (s[0] == 'L')
			data->lenght = 'Z';
		else
			data->lenght = s[0];
	}
	return (s + 1);
}

/*
** определение флагов
*/

char	*ft_updateflag(char *s, t_argdata *data)
{
	if (*s == '#')
		data->hash = '#';
	if (*s == ' ')
		data->space = '!';
	if (*s == '-')
		data->minus = '-';
	if (*s == '+')
		data->plus = '+';
	if (*s == '\'')
		data->apostrophe = '\'';
	if (*s == '*')
		data->star = '*';
	if (*s == '0')
		data->zero = '0';
	if (*s == '$')
		data->dollar = '$';
	return (s);
}

/*
** определение ширины и  поиск модификаторов точности
*/

char	*ft_updateints(t_argdata *data, char *s, int i)
{
	if (i == 0)
		data->size = ft_atoi(s);
	if (i == 1)
	{
		data->precision = ft_updateprecision(s);
		while (s[0] == '.')
			s++;
	}
	while (ft_isdigit(s[0]) == 1)
		s++;
	return (s);
}

/*
** заполнение структуры модификаторами формата
*/

void	ft_fillstruct(t_argdata *data)
{
	char *s;

	s = data->form_input;
	while (*s != '\0')
	{
		if ((ft_isdigit(s[0]) == 1) && (s[0] != '0'))
			s = ft_updateints(data, s, 0);
		if (s[0] == '.')
			s = ft_updateints(data, s, 1);
		if (ft_strchr(LENGHT, s[0]))
			s = ft_updatelenght(s, data);
		if (ft_strchr(CONVERT, s[0]))
			data->conversion = *s;
		if (ft_strchr(FLAGS, s[0]))
			s = ft_updateflag(s, data);
		s++;
	}
}
