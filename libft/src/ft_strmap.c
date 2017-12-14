/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:41:34 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/07 22:32:50 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
		res = (char *)malloc(sizeof(char) * (i + 1));
		if (res == NULL)
			return (0);
		res[i--] = '\0';
		while (i >= 0)
		{
			res[i] = f(s[i]);
			i--;
		}
		return (res);
	}
	return (0);
}
