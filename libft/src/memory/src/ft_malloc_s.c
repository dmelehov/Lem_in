/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:52:20 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 15:21:19 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_malloc_s(size_t nbr, size_t size)
{
	void	*mem;

	mem = NULL;
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		M_ERROR(-1, "Bad size malloc");
	if (!(mem = malloc(size * nbr)))
		M_ERROR(-1, "Malloc allocation error");
	return (mem);
}

void	*ft_realloc_s(void *ptr, size_t nbr, size_t size)
{
	void	*mem;

	mem = ft_realloc(ptr, nbr * size);
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		M_ERROR(-1, "Bad size realloc");
	if (!ptr)
		M_ERROR(-1, "Realloc allocation error");
	return (mem);
}

void	ft_free_s(void **ptr)
{
	if (*ptr == NULL)
		M_ERROR(-1, "ptr == NULL");
	free(*ptr);
	*ptr = NULL;
}
