/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:34:12 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 09:35:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *res;

	res = dst;
	while (*src != '\0')
		*(dst++) = *(src++);
	*dst = '\0';
	return (res);
}
