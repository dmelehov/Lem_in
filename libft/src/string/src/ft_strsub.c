/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:08:53 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 19:39:11 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (s != NULL)
	{
		if (!(res = ft_strnew(len)))
			return (NULL);
		while (len--)
			res[len] = s[start + len];
		return (res);
	}
	return (NULL);
}
