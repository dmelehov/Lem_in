/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:20:33 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/24 22:08:48 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static inline void		ft_array_delete(void *ptr)
{
	(void)ptr;
}

static inline size_t	ft_array_realloc(size_t size)
{
	return (size << 1);
}

bool					ft_array_init(t_array *v_this,
							size_t (*ft_realloc)(size_t size),
							void (*ft_delete)(void *ptr), size_t type_size)
{
	v_this->v_size = 0;
	v_this->v_capacity = 0;
	v_this->ft_realloc = ft_realloc;
	if (ft_realloc == NULL)
		v_this->ft_realloc = ft_array_realloc;
	v_this->ft_delete = ft_delete;
	if (ft_delete == NULL)
		v_this->ft_delete = ft_array_delete;
	if ((v_this->v_data = ft_malloc_s(2, type_size)) == NULL)
	{
		M_ERROR(-1, "Bad alloc");
		return (false);
	}
	ft_memset(v_this->v_data, 0, 2 * type_size);
	v_this->v_capacity = 2;
	v_this->v_type_size = type_size;
	return (true);
}

void					ft_array_clear(t_array *v_this)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	ptr = (char *)v_this->v_data;
	size = v_this->v_size * v_this->v_type_size;
	while (i < size)
	{
		v_this->ft_delete((void*)(ptr + i));
		i = i + v_this->v_type_size;
	}
	v_this->v_size = 0;
}

void					ft_array_destroy(t_array *v_this)
{
	D_ARRAY(clear)(v_this);
	ft_free_s((void **)&v_this->v_data);
	v_this->v_size = 0;
	v_this->v_type_size = 0;
	v_this->v_capacity = 0;
	v_this->v_data = 0;
	v_this->ft_delete = NULL;
	v_this->ft_realloc = NULL;
}
