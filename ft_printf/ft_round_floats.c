/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:00:07 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 16:54:58 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** функции округления числовых и строковых значений флоутов
*/

long double	ft_round_up(long double t)
{
	long double d;

	d = (uintmax_t)t;
	if (t <= d)
		return (d);
	return (d + 1);
}

long double	ft_round_down(long double t)
{
	long double d;

	d = (uintmax_t)t;
	if (t >= d)
		return (d);
	return (d - 1);
}

long double	ft_round_fraction(long double t)
{
	long double up;
	long double down;

	up = ft_round_up(t);
	down = ft_round_down(t);
	if (t - down == 0.5 && !((uintmax_t)down ^ 1))
		return (down);
	else if (up - t == 0.5)
		return (up);
	if (t - down >= 0.5)
		return (up);
	else
		return (down);
}

/*
** условие направления полученой строки в функцию округления флоута в строке
*/

char		*ft_get_rounded_str(long double x, char *s)
{
	x = ft_round_fraction(x);
	if (x >= 10)
		s = ft_append(ft_round_dec_string(s, ft_strlen(s) - 1), "0", 0);
	else
		s = ft_append(s, ft_uitoa((intmax_t)x, 10), 3);
	return (s);
}

/*
** округлениe флоута в строке
*/

char		*ft_round_dec_string(char *s, int len)
{
	if (s[len] != '.' && len >= 0)
	{
		s[len]++;
		if (s[len] > 57)
		{
			s[len] = 48;
			s = ft_round_dec_string(s, len - 1);
		}
	}
	if (len < 0)
		s = ft_append("1", s, 0);
	return (s);
}
