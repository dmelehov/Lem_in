/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:23 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/07 20:53:07 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = (void *)malloc(size);
	if (s == NULL)
		return (NULL);
	while (size--)
		*(unsigned char *)(s + size) = 0;
	return (s);
}
