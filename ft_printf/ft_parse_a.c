/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:02:51 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 20:59:41 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_iter_hexdec(char *s)
{
	s[0]++;
	if (s[0] == 58)
		s[0] += 39;
}

char			*ft_round_hexdec(char *s, int i, int j)
{
	if (j == i)
		return (s);
	while (j > i)
		if (s[j--] >= 56)
			ft_iter_hexdec(s + j);
	if (s[i] > 56)
		ft_iter_hexdec(s + i - 1);
	s[i] = '\0';
	i--;
	while (s[i] > 102 || s[i] == '.')
	{
		if (s[i] == '.')
			i--;
		else if (s[i] > 102)
		{
			s[i] = 48;
			if (s[i - 1] == '.')
				i--;
			ft_iter_hexdec(s + i - 1);
		}
		i--;
	}
	return (s);
}

char			*ft_get_fract_part_a(long double x, char *s, t_argdata *data)
{
	int i;

	i = ft_strlen(s);
	while (x > 0)
	{
		x = (x - (intmax_t)x) * 16;
		if (x != 0)
			s = ft_append(s, ft_uitoa((intmax_t)x, 16), 3);
	}
	if (data->precision == -1)
		data->precision = ft_strlen(s) - i;
	else if (data->precision > ((int)ft_strlen(s) - i))
		while (data->precision > ((int)ft_strlen(s) - i))
			s = ft_append(s, "0", 1);
	else if (data->precision < (int)ft_strlen(s))
		s = ft_round_hexdec(s, data->precision + i, ft_strlen(s));
	return (s);
}

long double		ft_get_a_exp(long double x, int *exp, int base)
{
	while (x >= base)
	{
		x /= 2;
		(*exp)++;
	}
	while ((x * 2) > 0 && (x * 2) < base)
	{
		x *= 2;
		(*exp)--;
	}
	return (x);
}

char			*ft_parse_a(long double d, t_argdata *data, char *s)
{
	int			exp;
	int			base;
	long double x;

	exp = 0;
	if (data->lenght == 'Z')
		base = 16;
	else
		base = 2;
	s = ft_append(s, "0x", 1);
	x = ft_get_a_exp(d, &exp, base);
	s = ft_append(s, ft_uitoa((intmax_t)x, 16), 3);
	if (data->precision != 0 && (x - (intmax_t)x) != 0.0)
		s = ft_append(s, ".", 1);
	s = ft_get_fract_part_a(x, s, data);
	s = ft_append(s, "p", 1);
	if (exp < 0)
		s = ft_append(s, ft_checkneg(exp, 10), 1);
	else if (exp >= 0)
	{
		s = ft_append(s, "+", 1);
		s = ft_append(s, ft_uitoa(exp, 10), 3);
	}
	return (s);
}
