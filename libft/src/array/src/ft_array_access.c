/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:12:12 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 17:13:02 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*mf_array_data(t_array *v_this)
{
	return (v_this->v_data);
}

void	*mf_array_at(t_array *v_this, size_t index)
{
	if (index >= v_this->v_size)
	{
		M_ERROR(-1, "Out of range");
		return (NULL);
	}
	return ((void *)((uintptr_t)v_this->v_data + index * v_this->v_type_size));
}
