/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:39:36 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/10 15:42:18 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Write input to the character string not more than s_size bytes
*/

int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strncpy(s, str, size);
	free(str);
	return (ans);
}

/*
** Write input to the character string
*/

int		ft_vsprintf(char *s, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strcpy(s, str);
	free(str);
	return (ans);
}

/*
**  Allocate the character string and write input to it
*/

int		ft_asprintf(char **ret, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ans);
}

/*
** Write input to the character string not more than s_size bytes
*/

int		ft_snprintf(char *s, size_t size, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsnprintf(s, size, format, ap);
	va_end(ap);
	return (ans);
}

/*
** Write input to the character string
*/

int		ft_sprintf(char *s, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsprintf(s, format, ap);
	va_end(ap);
	return (ans);
}
