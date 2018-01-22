/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:00:08 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 17:18:33 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

bool	ft_array_foreach(t_array *v_this, bool (*funct)(void *data))
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	ptr = (char *)v_this->v_data;
	size = v_this->v_size * v_this->v_type_size;
	while (i < size)
	{
		if (funct((void *)(ptr + i)) == false)
			return (false);
		i = i + v_this->v_type_size;
	}
	return (true);
}
