/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 21:00:40 by dmelehov          #+#    #+#             */
/*   Updated: 2017/05/17 20:21:04 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** вспомогательные функции для обработки значений и строк
*/

/*
** проверяет наличие точного совпадение подстроки
** в строке и возвращает 1 если результат положительный
*/

int		ft_str_isin(char *big, char *little)
{
	if (big && little)
	{
		while (*big == *little)
		{
			big++;
			little++;
			if (*little == '\0')
				return (1);
		}
	}
	return (0);
}

/*
** проверяет отсутствие цифр в строке формата после указателя
** возвращает 1 в случае отсутствия
*/

int		ft_nonums_after(char *s)
{
	while (*s)
	{
		if (ft_isdigit(s[0]) == 1)
			return (0);
		else if (s[0] == '.')
		{
			s++;
			while (ft_isdigit(s[0]) && *s)
				s++;
		}
		s++;
	}
	return (1);
}

/*
** обрезает ноли в конце строки
*/

char	*ft_cut_zero(char *s, int len, t_argdata *data)
{
	if (data->precision == 0)
		return (s);
	while (s[len] == 48)
		s[len--] = '\0';
	if (s[len] == '.')
		s[len] = '\0';
	return (s);
}

/*
** возвращает новую строку зеркальную заданной
*/

char	*ft_revstr(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = ft_strdup(str);
	j = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		str[j++] = s[i--];
	}
	ft_strdel(&s);
	return (str);
}

/*
** освобождает память выделенную под двумерный массив чаров
*/

void	ft_free_2d_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_memdel((void **)&(arr[i]));
		i++;
	}
	ft_memdel((void **)arr);
}
