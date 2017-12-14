/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:37:28 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/19 19:06:27 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char src;

	src = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == src)
		{
			*(unsigned char *)d = *(unsigned char *)s;
			return ((unsigned char *)d + 1);
		}
		*(unsigned char *)d++ = *(unsigned char *)s++;
	}
	return (NULL);
}
