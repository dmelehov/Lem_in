/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:54:50 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/18 20:17:54 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Allocate the character string and write input to it
*/

int		ft_vasprintf(char **s, char const *format, va_list ap)
{
	int	ans;

	ans = ft_create_func_arr(ft_strdup(format), ap, s);
	return (ans);
}

/*
** Write input to the given file descriptor
*/

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	char		*s;
	int			ans;

	ans = ft_vasprintf(&s, format, ap);
	write(fd, s, ans);
	free(s);
	return (ans);
}

/*
** Write input to the given file descriptor
*/

int		ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ans);
}

/*
**  Write output to the stdout
*/

int		ft_vprintf(char const *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

/*
**  Write output to the stdout
*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vprintf(format, ap);
	va_end(ap);
	return (ans);
}
