/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:25:10 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/09 21:48:55 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*res;

	i = 0;
	j = 0;
	l = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i])
			i++;
		while (s2[j])
			j++;
		if (!(res = (char *)malloc(i + j + 1)))
			return (NULL);
		while (*s1 != '\0')
			res[l++] = *s1++;
		while (*s2 != '\0')
			res[l++] = *s2++;
		res[l] = '\0';
		return (res);
	}
	return (0);
}
