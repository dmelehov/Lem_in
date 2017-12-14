/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:33:29 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/09 18:05:02 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
			i++;
		res = (char *)malloc(sizeof(char) * (i + 1));
		if (res == NULL)
			return (0);
		res[i--] = '\0';
		while (i != 0)
		{
			res[i] = f(i, s[i]);
			i--;
		}
		res[i] = f(i, s[i]);
		return (res);
	}
	return (0);
}
