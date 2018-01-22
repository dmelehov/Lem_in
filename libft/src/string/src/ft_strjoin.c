/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:25:10 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 15:46:58 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(ft_strcpy(res, s1), s2);
		return (res);
	}
	return (NULL);
}
