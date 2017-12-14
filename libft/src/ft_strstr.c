/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:14:00 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/03 14:47:00 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	j = 0;
	l = 0;
	while (little[l])
		l++;
	if (l == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
		{
			if (j == l - 1)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
