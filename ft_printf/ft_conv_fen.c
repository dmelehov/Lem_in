/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_fen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:17:17 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 21:05:20 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** принятие и отправка на обработку аргументов типа f, F, e, E, n
*/

char	*ft_cv_n(va_list *ap, t_argdata *data)
{
	int	*f;

	f = va_arg(*ap, int *);
	if (data->lenght == 'H')
		*(char *)f = (char)data->ans;
	else if (data->lenght == 'h')
		*(short *)f = (short)data->ans;
	else if (data->lenght == 'l' || data->lenght == 'z')
		*(long *)f = (long)data->ans;
	else if (data->lenght == 'L')
		*(long long *)f = (long long)data->ans;
	else if (data->lenght == 'j')
		*(intmax_t *)f = (intmax_t)data->ans;
	else
		*(int *)f = (int)data->ans;
	return (ft_strdup(""));
}

char	*ft_cv_be(va_list *ap, t_argdata *data)
{
	return (ft_cv_e(ap, data));
}

char	*ft_cv_e(va_list *ap, t_argdata *data)
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
	s = ft_parse_floats(f, data);
	return (s);
}

char	*ft_cv_bf(va_list *ap, t_argdata *data)
{
	return (ft_cv_f(ap, data));
}

char	*ft_cv_f(va_list *ap, t_argdata *data)
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
	s = ft_parse_floats(f, data);
	return (s);
}
