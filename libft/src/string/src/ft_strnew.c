/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:27:03 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 15:56:07 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	void	*s;

	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	size += 1;
	while (size--)
		*(unsigned char *)(s + size) = '\0';
	return (s);
}
