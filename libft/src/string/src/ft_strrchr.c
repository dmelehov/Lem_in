/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:58:22 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 16:18:50 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	c = ((char)c);
	while (i >= 0)
	{
		if (s[i] == c && ft_isascii(c))
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)(s + i));
	return (0);
}
