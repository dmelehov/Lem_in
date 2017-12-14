/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:40:52 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 20:47:35 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** проверяет полученый аргумент на пригодность к обработке
*/

char	*ft_check_infinity(long double f)
{
	if (!(f == f))
		return (ft_strdup("nan"));
	if (f == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (f == 1.0 / 0.0)
		return (ft_strdup("inf"));
	return (NULL);
}

/*
** определяет полученый аргумент соответствующей функции
*/

char	*ft_parse_floats(long double d, t_argdata *data)
{
	char	*s;
	int		neg;
	int		exp;

	s = ft_strnew(1);
	neg = 0;
	if (d < 0.0)
	{
		neg = 1;
		d = -d;
	}
	exp = ft_find_exp_value(d);
	if (data->conversion == 'f' || data->conversion == 'F')
		s = ft_dtoa(d, s, data);
	else if (data->conversion == 'e' || data->conversion == 'E')
		s = ft_exponent(d, s, data, exp);
	else if (data->conversion == 'g' || data->conversion == 'G')
		s = g_cv_switcher(d, data, s, exp);
	if (neg == 1)
		s = ft_append("-", s, 2);
	return (s);
}

/*
** аналог itoa для floats
*/

char	*ft_dtoa(long double d, char *s, t_argdata *data)
{
	long double x;
	int			i;

	i = 0;
	s = ft_get_whole_part(d, s, data);
	if (data->precision == 0)
		return (s);
	if (data->precision != 0 || data->hash == '#')
		s = ft_append(s, ".", 1);
	x = (d - (intmax_t)d) * 10;
	while (x != 0 || i < data->precision)
	{
		if (i + 1 == data->precision)
			return (ft_get_rounded_str(x, s));
		s = ft_append(s, ft_uitoa((intmax_t)x, 10), 3);
		x = x - (intmax_t)x;
		x *= 10;
		i++;
	}
	return (s);
}

/*
** представление аргумента в экспоненциальной форме записи
*/

char	*ft_exponent(long double d, char *s, t_argdata *data, int exp)
{
	long double x;

	x = ft_normalize_float(d, exp);
	if (ft_check_normalize(x, data->precision) || (intmax_t)x == 10)
	{
		x /= 10;
		exp++;
	}
	s = ft_dtoa(x, s, data);
	if (data->conversion == 'g' || data->conversion == 'G')
		s = ft_cut_zero(s, ft_strlen(s) - 1, data);
	s = ft_append(s, "e", 1);
	if (exp < 0)
	{
		s = ft_append(s, "-", 1);
		exp = -exp;
	}
	else
		s = ft_append(s, "+", 1);
	if (exp < 10)
		s = ft_append(s, "0", 1);
	s = ft_append(s, ft_uitoa(exp, 10), 2);
	return (s);
}

/*
** в случае G типа превращения перенаправляет
** полученый аргумент в соответствующий тип обработки
*/

char	*g_cv_switcher(long double d, t_argdata *data, char *s, int exp)
{
	if (exp < -4 || exp >= data->precision)
	{
		data->precision--;
		s = ft_exponent(d, s, data, exp);
	}
	else
	{
		data->precision = data->precision - exp - 1;
		s = ft_dtoa(d, s, data);
	}
	return (s);
}
