/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:52:20 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 20:59:59 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_malloc_s(size_t nbr, size_t size)
{
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		M_ERROR(-1, "Bad size malloc");
	return (malloc(size * nbr));
}

void	*ft_realloc_s(void *ptr, size_t nbr, size_t size)
{
	if (size == 0 || nbr == 0 || nbr > SIZE_MAX / size)
		M_ERROR(-1, "Bad size realloc");
	return (realloc(ptr, nbr * size));
}

void	ft_free_s(void **ptr)
{
	if (*ptr == NULL)
		M_ERROR(-1, "ptr == NULL");
	free(*ptr);
	*ptr = NULL;
}
