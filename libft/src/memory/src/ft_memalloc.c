/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:23 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 16:31:14 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = (void *)malloc(size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
