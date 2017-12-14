/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:39:46 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/10 20:46:46 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** принятие и отправка на обработку аргументов типа p,o,O,x,X
*/

char	*ft_cv_p(va_list *ap, t_argdata *data)
{
	void	*t;
	char	*s;

	t = va_arg(*ap, void *);
	s = ft_uitoa((uintmax_t)t, 16);
	data->hash = '#';
	return (s);
}

char	*ft_cv_lx(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	s = ft_apply_lenght_uox(data, t, 16);
	return (s);
}

char	*ft_cv_x(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	s = ft_apply_lenght_uox(data, t, 16);
	return (s);
}

char	*ft_cv_lo(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	data->lenght = 'l';
	s = ft_apply_lenght_uox(data, t, 8);
	if ((t == 0) && (data->hash == '#') && (data->precision == 0))
		data->precision++;
	return (s);
}

char	*ft_cv_o(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	s = ft_apply_lenght_uox(data, t, 8);
	if ((t == 0) && (data->hash == '#') && (data->precision == 0))
		data->precision++;
	return (s);
}
