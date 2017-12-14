/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatparsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:51:16 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/17 08:06:54 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** применение к аргументу соответствующей функции
*/

void	ft_apply_funct(va_list *ap,
		t_argdata *data, char *func(va_list *, t_argdata *), char **s)
{
	char	*str;
	int		i;

	i = 0;
	str = (*func)(ap, data);
	if (str)
	{
		str = ft_apply_modifyers(str, data);
		while (str[i])
			(*s)[(data->ans)++] = str[i++];
		ft_bzero(str, ft_strlen(str));
		ft_strdel(&str);
	}
	else
		ft_nullcharprint(str, data, s);
}

/*
** парсинг аргументов
*/

int		ft_argparser(t_argdata *data, va_list *ap,
		char **s, void const *functions[])
{
	char const	*conv = "cCsSdDioOuUxXpfFaAeEgGn";
	int			i;

	i = ft_strchr(conv, data->conversion) - conv;
	if (data->star)
		ft_apply_star(ap, data);
	if (data->form_input[ft_strlen(data->form_input) - 1] == 32)
		data->conversion = '\0';
	if (data->conversion)
		ft_apply_funct(ap, data, functions[i], s);
	return (ft_strlen(data->form_input) + 1);
}

/*
** печать префиксов
*/

int		ft_get_prefix(char *format, char **s, int *ans)
{
	int i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
	{
		if (format[i] == '{')
		{
			i += ft_check_color(format + i, s, ans);
			if (format[i] == '\0')
				break ;
		}
		(*s)[(*ans)++] = format[i];
		i++;
	}
	return (i);
}

/*
** парсинг строки формата
*/

int		ft_formatparser(char *format, va_list ap,
		char **s, void const *functions[])
{
	static t_argdata	*data;
	int					ans;
	int					i;

	i = 0;
	ans = 0;
	*s = ft_strnew(3000);
	while (*format != '\0')
	{
		if (*format != '%' && *format != '\0')
			format += ft_get_prefix(format, s, &ans);
		else if (*format == '%' && format[1] != '\0')
		{
			data = ft_get_argdata(data, format, i++, ans);
			format += ft_argparser(data, (va_list *)(ap), s, functions);
			ans = data->ans;
			ft_free_struct(data);
		}
		else if (*format == '%' && format[1] == '\0')
			format++;
	}
	return (ans);
}

/*
** создание массива адресов функций. дополняемо ;)
*/

int		ft_create_func_arr(char *format, va_list ap, char **s)
{
	int			ans;
	void const	*functions[] = {&ft_cv_c, &ft_cv_wc, &ft_cv_s, &ft_cv_ws,
	&ft_cv_d, &ft_cv_ld, &ft_cv_i, &ft_cv_o, &ft_cv_lo, &ft_cv_u, &ft_cv_lu,
	&ft_cv_x, &ft_cv_lx, &ft_cv_p, &ft_cv_f, &ft_cv_bf, &ft_cv_a, &ft_cv_ba,
	&ft_cv_e, &ft_cv_be, &ft_cv_g, &ft_cv_bg, &ft_cv_n};

	ans = ft_formatparser(format, ap, s, functions);
	ft_strdel(&format);
	return (ans);
}
