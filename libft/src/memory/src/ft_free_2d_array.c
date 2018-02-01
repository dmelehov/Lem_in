/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:25:41 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 15:37:36 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_free_2d_array(void **data)
{
	size_t	i;
	char	**arr;

	i = 0;
	arr = (char **)data;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	free(arr);
}
