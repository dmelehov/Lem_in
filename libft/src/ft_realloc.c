/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:00:23 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/26 13:18:38 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;
	size_t	osz;

	osz = 0;
	while (((char *)ptr)[osz])
		osz++;
	if (ptr != NULL)
	{
		res = malloc(size);
		if (size < osz)
			osz = size;
		res = ft_memcpy(res, ptr, osz);
		free(ptr);
		return (res);
	}
	res = malloc(size);
	return (res);
}
