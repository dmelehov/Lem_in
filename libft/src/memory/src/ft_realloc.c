/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:00:23 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 17:26:43 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

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
		ft_memdel(&ptr);
		return (res);
	}
	res = malloc(size);
	return (res);
}
