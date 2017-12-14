/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:08:53 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/09 20:24:52 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char *res;

	if (s != NULL)
	{
		if (!(res = (char *)malloc(len + 1)))
			return (NULL);
		res[len] = '\0';
		while (len--)
			res[len] = s[start + len];
		return (res);
	}
	return (NULL);
}
