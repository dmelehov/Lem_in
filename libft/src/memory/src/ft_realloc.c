/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:00:23 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 15:22:15 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	res = NULL;
	if (size == 0)
		return (res);
	if (ptr != NULL)
	{
		res = ft_malloc_s(1, size);
		res = ft_memcpy(res, ptr, size);
		ft_memdel(&ptr);
		return (res);
	}
	return (res);
}
