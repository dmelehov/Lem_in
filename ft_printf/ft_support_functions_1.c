/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:55:34 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/15 20:11:50 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** вспомогательные функции для обработки значений и строк
*/

/*
** аналог джоина с освобождением памяти
*/

char	*ft_append(char *s1, char *s2, int i)
{
	char	*res;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		res = ft_strcat(ft_strcpy(res, s1), s2);
		if (i == 1)
			ft_strdel(&s1);
		if (i == 2)
			ft_strdel(&s2);
		if (i == 3)
		{
			ft_strdel(&s1);
			ft_strdel(&s2);
		}
		return (res);
	}
	return (0);
}

/*
** делает буквы заглавными
*/

char	*ft_capitalizer(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

/*
** рекурсивно подсчитывает длинну числа
*/

int		ft_findintlen(uintmax_t t, int b)
{
	int	i;

	i = 1;
	if (t != 0)
		i += ft_findintlen(t / b, b);
	return (i);
}

/*
** переводит число из десятичной в 1 - 16 сист.счисления и возвращает строку
*/

char	*ft_uitoa(uintmax_t t, int b)
{
	char const	*base = "0123456789abcdef";
	char		*res;
	int			j;
	int			i;

	i = ft_findintlen(t / b, b);
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i] = '\0';
	i--;
	while (t >= (uintmax_t)b)
	{
		j = t % b;
		res[i] = base[j];
		t /= b;
		i--;
	}
	res[i] = base[t];
	return (res);
}

/*
** проверяет число на отрицательность
*/

char	*ft_checkneg(intmax_t t, int b)
{
	char		*s;
	intmax_t	d;

	if (t < 0)
	{
		d = -t;
		s = ft_append("-", ft_uitoa(d, b), 2);
	}
	else
		s = ft_uitoa(t, b);
	return (s);
}
