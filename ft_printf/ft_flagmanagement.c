/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagmanagement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:00:05 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 20:32:10 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** применение и модификация флагов
*/

/*
** применение флага '
*/

char	*ft_apply_apostrophe(char *str, t_argdata *data)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	data->apostrophe = '\0';
	if (i < 3)
		s = str;
	else
		s = ft_strnew(0);
	while (i > 3)
	{
		s = ft_append(s, ft_strsub(str, 0, 3), 3);
		s = ft_append(s, ",", 1);
		str += 3;
		i -= 3;
		if (i <= 3)
			s = ft_append(s, ft_strsub(str, 0, ft_strlen(str)), 3);
	}
	return (ft_revstr(s));
}

/*
** применение флага #
*/

char	*ft_apply_hash(char *s, t_argdata *data)
{
	if ((ft_strcmp(s, "0") == 0 || *s == '\0') && data->conversion != 'p')
		return (s);
	if (ft_strchr("pxX", data->conversion))
		return (ft_append("0x", s, 2));
	if (ft_strchr("oO", data->conversion) && s[0] != '0')
		return (ft_append("0", s, 2));
	return (s);
}

/*
** применение флага 0
*/

char	*ft_apply_zero(char *s, t_argdata *data, int neg)
{
	if (data->hash && ft_strchr("pxX", data->conversion))
		data->size -= 2;
	if (data->hash && ft_strchr("oO", data->conversion))
		data->size -= 1;
	if (data->space)
		data->size -= 1;
	if (data->plus || neg == 1)
		data->size -= 1;
	s = ft_apply_size(s, data, "0");
	return (s);
}

/*
** модификация флагов, учет исключений и прочее
*/

void	ft_update_flag_values(t_argdata *data, int neg)
{
	if (data->space && (data->plus || neg == 1))
		data->space = '\0';
	if (data->zero && (data->minus || (ft_strchr(data->form_input, '.')
		&& ft_strchr("dDiuU", data->conversion))))
		data->zero = '\0';
	if (data->plus && neg == 1)
		data->plus = '\0';
}

/*
** менеджер обработки флагов
*/

char	*ft_apply_flags(char *s, t_argdata *data, int neg)
{
	ft_update_flag_values(data, neg);
	if (data->zero)
		s = ft_apply_zero(s, data, neg);
	if (data->hash && ft_strchr("poOxXfFeEaAgG", data->conversion))
		s = ft_apply_hash(s, data);
	if (data->plus && ft_strchr("dDi", data->conversion))
		s = ft_append("+", s, 2);
	if (data->space && ft_strchr("dDi", data->conversion))
		s = ft_append(" ", s, 2);
	return (s);
}
