/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:33:29 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 15:49:40 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (s != NULL && f != NULL)
	{
		if (!(res = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		return (res);
	}
	return (0);
}
