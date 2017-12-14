/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:12:42 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/07 17:33:39 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)dst;
	if (src < dst)
		while (len--)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
	else if (src >= dst)
		while (len--)
			(*(unsigned char *)dst++ = *(unsigned char *)src++);
	return (tmp);
}
