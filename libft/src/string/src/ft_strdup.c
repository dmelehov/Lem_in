/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:00:27 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/08 18:18:48 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;

	if (!(temp = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strcpy(temp, s1);
	return (temp);
}
