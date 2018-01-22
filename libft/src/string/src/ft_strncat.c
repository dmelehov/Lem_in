/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:48:03 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 15:13:19 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*res;

	res = s1;
	s1 = s1 + ft_strlen(s1);
	while (*s2 && n--)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (res);
}
