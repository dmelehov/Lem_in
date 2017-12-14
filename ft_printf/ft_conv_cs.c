/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:48:40 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 20:24:54 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** принятие и отправка на обработку аргументов типа c,C,s,S
** конвертация wchar
*/

char	*ft_conv_wchar(wchar_t v)
{
	unsigned char *r;

	r = (unsigned char *)ft_strnew(4);
	if (v <= 127)
		r[0] = v;
	else if (v <= 2047)
	{
		r[0] = ((v & 1984) >> 6 | 192);
		r[1] = ((v & 63) | 128);
	}
	else if (v <= 65535)
	{
		r[0] = ((v >> 12) | 224);
		r[1] = ((v & 4032) >> 6 | 128);
		r[2] = ((v & 63) | 128);
	}
	else if (v <= 2097151)
	{
		r[0] = ((v >> 18) | 240);
		r[1] = ((v & 258048) >> 12 | 128);
		r[2] = ((v & 4032) >> 6 | 128);
		r[3] = ((v & 63) | 128);
	}
	return ((char *)r);
}

char	*ft_cv_ws(va_list *ap, t_argdata *data)
{
	wchar_t *t;
	int		i;
	int		j;
	char	*r;

	i = 0;
	r = ft_strnew(0);
	t = va_arg(*ap, wchar_t *);
	if (t == NULL)
		return (ft_strdup("(null)"));
	while (t[i])
	{
		r = ft_append(r, ft_conv_wchar(t[i]), 3);
		if (((int)ft_strlen(r) > data->precision) && (data->precision >= 1))
		{
			data->precision -= (data->precision - j);
			return (r);
		}
		j = ft_strlen(r);
		i++;
	}
	return (r);
}

char	*ft_cv_s(va_list *ap, t_argdata *data)
{
	char *s;

	s = NULL;
	if (data->lenght == 'l')
		return (ft_cv_ws(ap, data));
	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	return (ft_strdup(s));
}

char	*ft_cv_wc(va_list *ap, t_argdata *data)
{
	wchar_t	v;
	char	*s;

	if (data->conversion == 'C')
	{
		s = ft_strnew(1);
		s[0] = (char)va_arg(*ap, int);
		return (s);
	}
	v = va_arg(*ap, wchar_t);
	if (v == 0)
		return (NULL);
	s = ft_conv_wchar(v);
	return (s);
}

char	*ft_cv_c(va_list *ap, t_argdata *data)
{
	char	*s;
	int		i;

	s = ft_strnew(1);
	i = ft_strlen(data->form_input);
	if (ft_strcmp(s, data->form_input) == 0)
		return (s);
	if (data->lenght == 'l')
	{
		data->conversion = 'C';
		return (ft_cv_wc(ap, data));
	}
	if (ft_strchr("c", (data->form_input[i - 1])) != 0)
	{
		*s = (char)va_arg(*ap, int);
		if (*s == 0 || !(*s))
			return (NULL);
	}
	else
		*s = data->form_input[i - 1];
	return (s);
}
