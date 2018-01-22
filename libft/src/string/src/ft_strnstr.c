/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:29:13 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 16:11:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strnstr(const char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = ft_strlen(little);
	if (l-- == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while ((big[i + j] == little[j]) && (i + j < len))
		{
			if (j == l)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
