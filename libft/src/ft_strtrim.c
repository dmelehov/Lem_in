/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:29:44 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/12 21:12:49 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_getend(char const *s)
{
	int i;

	i = 0;
	if (*s == '\0')
		return (-1);
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i--;
		if (i == 0)
			return (-1);
	}
	return (i);
}

static	int		ft_getstart(char const *s)
{
	int i;

	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	i = 0;
	if (s != NULL)
	{
		end = ft_getend(s);
		if (end + 1 == 0)
		{
			res = (char *)malloc(sizeof(char));
			res[0] = '\0';
			return (res);
		}
		start = ft_getstart(s);
		if (!(res = (char *)malloc(end - start + 2)))
			return (NULL);
		res[end - start + 1] = '\0';
		while (start <= end)
			res[i++] = s[start++];
		return (res);
	}
	return (0);
}
