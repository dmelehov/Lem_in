/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_modifyer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:14:56 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/23 22:44:20 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static bool	ft_array_realloc(t_array *v_this, size_t size)
{
	void	*tmp;

	tmp = v_this->v_data;
	v_this->v_data = ft_realloc_s(v_this->v_data, size, v_this->v_type_size);
	if (v_this->v_data == NULL)
	{
		v_this->v_data = tmp;
		M_ERROR(-1, "Bad alloc");
		return (false);
	}
	v_this->v_capacity = size;
	return (true);
}

bool		ft_array_push_back(t_array *v_this, void *data)
{
	char	*to;
	size_t	new_size;

	new_size = v_this->ft_realloc(v_this->v_capacity);
	if (v_this->v_size + 1 > v_this->v_capacity
		&& D_ARRAY(realloc)(v_this, new_size) == false)
		return (false);
	to = (char *)v_this->v_data;
	to = to + v_this->v_size * v_this->v_type_size;
	ft_memcpy(to, data, v_this->v_type_size);
	v_this->v_size = v_this->v_size + 1;
	return (true);
}

bool		ft_array_resize(t_array *v_this, size_t size)
{
	if (size < v_this->v_capacity)
	{
		M_ERROR(-1, "Size is lower than capacity");
		return (false);
	}
	return (D_ARRAY(realloc)(v_this, size));
}

void		ft_array_delete_if(t_array *v_this,
							bool (*ft_cmp)(void *d1, void *d2), void *data)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	ptr = (char *)v_this->v_data;
	size = v_this->v_size * v_this->v_type_size;
	while (i < size)
	{
		if (ft_cmp((void *)(ptr + i), data) == true)
		{
			ft_memcpy(ptr + i, ptr + i + v_this->v_type_size,
					size - i - v_this->v_type_size);
			ft_memset(ptr + size - v_this->v_type_size, 0, v_this->v_type_size);
			v_this->v_size = v_this->v_size - 1;
			size = v_this->v_size * v_this->v_type_size;
		}
		else
			i = i + v_this->v_type_size;
	}
}
