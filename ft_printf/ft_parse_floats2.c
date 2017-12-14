/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_floats2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:56:14 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 17:03:33 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** проверка числа на нормализованый вид
** для представления в экспоненциальной форме
*/

int				ft_check_normalize(long double x, int p)
{
	if ((intmax_t)x < 9)
		return (0);
	x = (x - (intmax_t)x) * 10;
	p--;
	while ((intmax_t)x == 9)
	{
		x = (x - (intmax_t)x) * 10;
		p--;
	}
	if ((intmax_t)x < 8)
		p++;
	if (p <= -1)
		return (1);
	else
		return (0);
}

/*
** приведение числа в нормализованый вид
** для представления в экспоненциальной форме
*/

long double		ft_normalize_float(long double x, int exp)
{
	if (exp < 0)
		while (exp++ < 0)
			x *= 10;
	else if (exp > 0)
		while (exp-- > 0)
			x /= 10;
	return (x);
}

/*
** определение значения экспоненты
*/

int				ft_find_exp_value(long double x)
{
	int exp;

	exp = 0;
	while (x > 0 && x < 1)
	{
		x *= 10;
		exp--;
	}
	while (x > 10)
	{
		x = x / 10;
		exp++;
	}
	return (exp);
}

/*
** проверка на девятки после запятой (необходимо ли округлять)
*/

int				ft_check_nine(long double x, int prec)
{
	while (prec >= 0 && (intmax_t)x >= 9)
	{
		x = (x - (intmax_t)x) * 10;
		prec--;
	}
	if (prec <= 0)
		return (1);
	return (0);
}

/*
** выделяет целую часть флоута
*/

char			*ft_get_whole_part(long double x, char *s, t_argdata *data)
{
	int	i;

	i = 0;
	while (x > 10)
	{
		x /= 10;
		i--;
	}
	while (i <= 0)
	{
		s = ft_append(s, ft_uitoa((intmax_t)x, 10), 3);
		x = (x - (intmax_t)x) * 10;
		i++;
	}
	if ((int)(x / 10) < (int)ft_round_fraction(x / 10) && data->precision == 0)
		return (ft_round_dec_string(s, ft_strlen(s) - 1));
	if (ft_round_fraction(x) >= 9 && ft_check_nine(x, data->precision))
		return (ft_round_dec_string(s, ft_strlen(s) - 1));
	return (s);
}
