/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:16:44 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/16 17:08:35 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wordcntr(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			if (s[i - 1] == c || i == 0)
				j++;
			i++;
		}
	}
	return (j);
}

static	int		ft_wordlen(char const *s, char c, size_t i)
{
	size_t	k;

	k = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		k++;
		i++;
	}
	return (k);
}

static	char	*ft_wordwrite(char const *s, char c, size_t i, size_t k)
{
	char	*res;
	size_t	l;

	(void)c;
	l = i - 1;
	if (!(res = (char *)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	res[k--] = '\0';
	while ((k + 1) != 0)
		res[k--] = s[l--];
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	if (s != NULL)
	{
		i[2] = ft_wordcntr(s, c);
		if (!(res = (char **)malloc(sizeof(char *) * (i[2] + 1))))
			return (NULL);
		i[2] = 0;
		while (s[i[0]] != '\0')
		{
			while ((s[i[0]] == c) && (s[i[0]] != '\0'))
				i[0]++;
			if (s[i[0]] == '\0')
				break ;
			NORM1();
			res[i[2]++] = ft_wordwrite(s, c, i[0], i[1]);
		}
		res[i[2]] = NULL;
		return (res);
	}
	return (0);
}
