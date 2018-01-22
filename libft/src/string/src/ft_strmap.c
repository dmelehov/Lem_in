/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:41:34 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 15:48:14 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (s)
	{
		if (!(res = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i])
		{
			res[i] = f(s[i]);
			i++;
		}
		return (res);
	}
	return (0);
}
