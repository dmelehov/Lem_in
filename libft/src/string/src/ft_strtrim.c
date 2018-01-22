/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:29:44 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 16:53:03 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#define SKIPCHAR "\n\t "

static	int		ft_getend(char const *s, int i)
{
	if (*s == '\0')
		return (-1);
	while (ft_strchr(SKIPCHAR, s[i]) && i > 0)
		i--;
	return (i <= 0 ? -1 : i);
}

static	int		ft_getstart(char const *s, int i)
{
	while (ft_strchr(SKIPCHAR, s[i]))
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*res;

	if (s)
	{
		end = ft_getend(s, ft_strlen(s) - 1);
		if (end == -1)
			return (ft_strnew(0));
		start = ft_getstart(s, 0);
		if (!(res = ft_strnew(end - start + 1)))
			return (NULL);
		return (ft_strncpy(res, s + start, end - start + 1));
	}
	return (0);
}

#undef SKIPCHAR
