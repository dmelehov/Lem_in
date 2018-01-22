/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:14:00 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 16:03:35 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t j;
	size_t l;

	j = 0;
	l = ft_strlen(little);
	if (l-- == 0)
		return ((char *)big);
	while (*big)
	{
		while (big[j] == little[j])
		{
			if (j == l)
				return ((char *)(big));
			j++;
		}
		j = 0;
		big++;
	}
	return (NULL);
}
