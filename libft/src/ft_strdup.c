/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:00:27 by dmelehov          #+#    #+#             */
/*   Updated: 2016/12/22 14:47:45 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (s1[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	temp[i] = '\0';
	i--;
	while ((i + 1) != 0)
	{
		temp[i] = s1[i];
		i--;
	}
	return (temp);
}
