/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifyers_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:09:29 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 20:15:34 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** применение модификаторов ширины, точности, длинны(к цифровым типам)
*/

/*
** применяет модификаторы длинны к di типам
*/

char	*ft_apply_lenght_di(intmax_t t, int base, t_argdata *data)
{
	char *s;

	s = NULL;
	if (!(data->lenght))
		s = ft_checkneg((int)t, base);
	else if (data->lenght == 'l')
		s = ft_checkneg((long)t, base);
	else if (data->lenght == 'L')
		s = ft_checkneg((long long)t, base);
	else if (data->lenght == 'j')
		s = ft_checkneg((intmax_t)t, base);
	else if (data->lenght == 'z')
		s = ft_checkneg((ssize_t)t, base);
	else if (data->lenght == 'h')
		s = ft_checkneg((short)t, base);
	else if (data->lenght == 'H')
		s = ft_checkneg((char)t, base);
	return (s);
}

/*
** применяет модификаторы длинны к uox типам
*/

char	*ft_apply_lenght_uox(t_argdata *data, uintmax_t t, int base)
{
	char *s;

	s = NULL;
	if (!(data->lenght))
		s = ft_uitoa((unsigned int)t, base);
	else if (data->lenght == 'l')
		s = ft_uitoa((unsigned long)t, base);
	else if (data->lenght == 'L')
		s = ft_uitoa((unsigned long long)t, base);
	else if (data->lenght == 'j')
		s = ft_uitoa((uintmax_t)t, base);
	else if (data->lenght == 'z')
		s = ft_uitoa((size_t)t, base);
	else if (data->lenght == 'h')
		s = ft_uitoa((unsigned short)t, base);
	else if (data->lenght == 'H')
		s = ft_uitoa((unsigned char)t, base);
	return (s);
}

/*
** применяет модификаторы точности
*/

char	*ft_apply_precision(char *s, t_argdata *data)
{
	if ((data->precision == 0) && (ft_strcmp(s, "0") == 0)
		&& !ft_strchr("fFgGaA", data->conversion))
		return (ft_strnew(0));
	if (ft_strchr("sS", data->conversion))
		if (data->precision != -1)
			s = ft_strsub(s, 0, data->precision);
	if (ft_strchr("dDiuUoOxXp", data->conversion))
	{
		if (data->precision == -1)
			data->precision = 1;
		if (ft_strchr("dDiuUoOpxX", data->conversion) && (*s != '\0'))
			while (data->precision > (int)ft_strlen(s))
				s = ft_append("0", s, 2);
	}
	return (s);
}

/*
** применяет модификаторы ширины
*/

char	*ft_apply_size(char *s, t_argdata *data, char *t)
{
	int i;

	i = ft_strlen(s);
	if (data->size > 0)
		data->size -= i;
	if (data->minus)
		while (data->size-- > 0)
			s = ft_append(s, t, 1);
	else
		while (data->size-- > 0)
			s = ft_append(t, s, 2);
	return (s);
}

/*
** обработка строки полученого аргумента
*/

char	*ft_apply_modifyers(char *s, t_argdata *data)
{
	int neg;

	neg = 0;
	if (s[0] == '-')
	{
		s = ft_strcpy(s, s + 1);
		neg = 1;
	}
	s = ft_apply_precision(s, data);
	s = ft_apply_flags(s, data, neg);
	if (data->apostrophe && ft_strchr("diu", data->conversion))
		s = ft_apply_apostrophe(ft_revstr(s), data);
	if (neg == 1)
		s = ft_append("-", s, 2);
	s = ft_apply_size(s, data, " ");
	if (ft_strchr("XFEGA", data->conversion))
		s = ft_capitalizer(s);
	return (s);
}
