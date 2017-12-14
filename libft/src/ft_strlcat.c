/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:25:42 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/06 01:47:45 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	while (dst[j] != '\0' && j < size)
		j++;
	if (j == size)
		return (j + i);
	size = size - j - 1;
	while (src[k] && k < size)
	{
		dst[k + j] = src[k];
		k++;
	}
	dst[k + j] = '\0';
	return (j + i);
}
