/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ga.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:22:54 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 17:19:05 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** принятие и отправка на обработку аргументов
** типа g, G, a, A, свитчер для G типа превращения
*/

char	*ft_cv_bg(va_list *ap, t_argdata *data)
{
	return (ft_cv_g(ap, data));
}

char	*ft_cv_g(va_list *ap, t_argdata *data)
{
	long double	f;
	char		*s;

	if (data->lenght == 'Z')
		f = va_arg(*ap, long double);
	else
		f = va_arg(*ap, double);
	s = ft_check_infinity(f);
	if (s)
		return (s);
	if (data->precision == -1)
		data->precision = 6;
	if (data->precision == 0)
		data->precision = 1;
	s = ft_parse_floats(f, data);
	s = ft_cut_zero(s, ft_strlen(s) - 1, data);
	return (s);
}

char	*ft_cv_ba(va_list *ap, t_argdata *data)
{
	return (ft_cv_a(ap, data));
}

char	*ft_cv_a(va_list *ap, t_argdata *data)
{
	char		*s;
	long double	f;

	if (data->lenght == 'Z')
		f = va_arg(*ap, long double);
	else
		f = va_arg(*ap, double);
	s = ft_check_infinity(f);
	if (s)
		return (s);
	s = ft_strnew(1);
	if (f < 0)
	{
		s[0] = '-';
		f = -f;
	}
	s = ft_parse_a(f, data, s);
	return (s);
}
