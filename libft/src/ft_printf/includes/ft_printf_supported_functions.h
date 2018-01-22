/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_supported_functions.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:04:28 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 13:29:01 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SUPPORTED_FUNCTIONS_H
# define FT_PRINTF_SUPPORTED_FUNCTIONS_H

/*
**  Write output to the stdout
*/

int				ft_printf(const char *format, ...);

/*
**  Write output to the stdout
*/

int				ft_vprintf(char const *format, va_list ap);

/*
** Write input to the given file descriptor
*/

int				ft_dprintf(int fd, char const *format, ...);

/*
** Write input to the given file descriptor
*/

int				ft_vdprintf(int fd, char const *format, va_list ap);

/*
**  Allocate the character string and write input to it
*/

int				ft_vasprintf(char **s, char const *format, va_list ap);

/*
** Write input to the character string
*/

int				ft_sprintf(char *s, char const *format, ...);

/*
** Write input to the character string not more than s_size bytes
*/

int				ft_snprintf(char *s, size_t size, char const *format, ...);

/*
**  Allocate the character string and write input to it
*/

int				ft_asprintf(char **ret, char const *format, ...);

/*
** Write input to the character string
*/

int				ft_vsprintf(char *s, char const *format, va_list ap);

/*
** Write input to the character string not more than s_size bytes
*/

int				ft_vsnprintf(char *s, size_t size,
	char const *format, va_list ap);

#endif
