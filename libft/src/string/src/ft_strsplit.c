/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:16:44 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/24 21:03:20 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static	int		count_words(char const *s, char c, int i)
{
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static	char	*get_next_split(char const **s, char c)
{
	char	*res;
	int		size;

	res = NULL;
	while (**s == c)
		(*s)++;
	if (**s != '\0')
	{
		if (ft_strchr(*s, c))
			size = ft_strchr(*s, c) - (*s);
		else
			size = ft_strchr(*s, '\0') - (*s);
		if (!(res = ft_strnew(size)) || size == 0)
			return (NULL);
		ft_strncpy(res, *s, size);
	}
	while (**s && **s != c)
		(*s)++;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (s != NULL)
	{
		words = count_words(s, c, 0);
		i = 0;
		if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
			return (NULL);
		res[words] = NULL;
		while (i < words)
			res[i++] = get_next_split(&s, c);
		return (res);
	}
	return (0);
}
