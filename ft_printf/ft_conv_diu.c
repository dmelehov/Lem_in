/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:42:11 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/10 20:43:51 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** принятие и отправка на обработку аргументов типа d,D,i,u,U
*/

char	*ft_cv_i(va_list *ap, t_argdata *data)
{
	intmax_t	t;
	char		*s;

	t = va_arg(*ap, intmax_t);
	s = ft_apply_lenght_di(t, 10, data);
	return (s);
}

char	*ft_cv_ld(va_list *ap, t_argdata *data)
{
	intmax_t	t;
	char		*s;

	t = va_arg(*ap, intmax_t);
	data->lenght = 'l';
	s = ft_apply_lenght_di(t, 10, data);
	return (s);
}

char	*ft_cv_d(va_list *ap, t_argdata *data)
{
	intmax_t	t;
	char		*s;

	t = va_arg(*ap, intmax_t);
	s = ft_apply_lenght_di(t, 10, data);
	return (s);
}

char	*ft_cv_lu(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	data->lenght = 'l';
	s = ft_apply_lenght_uox(data, t, 10);
	return (s);
}

char	*ft_cv_u(va_list *ap, t_argdata *data)
{
	uintmax_t	t;
	char		*s;

	t = va_arg(*ap, uintmax_t);
	s = ft_apply_lenght_uox(data, t, 10);
	return (s);
}
