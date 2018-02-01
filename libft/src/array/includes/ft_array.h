/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:14:54 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/25 17:24:36 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "../../../includes/libft.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct	s_array
{
	size_t		v_size;
	size_t		v_type_size;
	size_t		v_capacity;
	void		*v_data;
	void		(*ft_delete)(void *ptr);
	size_t		(*ft_realloc)(size_t size);
}				t_array;

# define F_ARRAY_AT(v, index, type) (type)mf_array_at(v, index)
# define F_ARRAY_DATA(v, type) (type)mf_array_data(v)
# define D_ARRAY(funct) ft_array_##funct

/*
**	ft_array_init.c
*/

bool			ft_array_init(t_array *v_this,
							size_t (*ft_realloc)(size_t size),
							void (*ft_delete)(void *ptr), size_t type_size);
void			ft_array_clear(t_array *v_this);
void			ft_array_destroy(t_array *v_this);

/*
**	ft_array_foreach.c
*/

bool			ft_array_foreach(t_array *v_this, bool (*funct)(void *data));
bool			ft_array_foreach_if(t_array *v_this,
					bool (*cmp)(void *data, void *value), void *value);

/*
**	ft_array_modifyer.c
*/

bool			ft_array_push_back(t_array *v_this, void *data);
bool			ft_array_resize(t_array *v_this, size_t size);
void			ft_array_delete_if(t_array *v_this,
							bool (*ft_cmp)(void *d1, void *d2), void *data);

/*
**	ft_array_capacity.c
*/

bool			ft_array_empty(const t_array *v_this);
size_t			ft_array_capacity(const t_array *v_this);
size_t			ft_array_size(const t_array *v_this);

/*
**	ft_array_access.c
*/

void			*mf_array_data(t_array *v_this);
void			*mf_array_at(t_array *v_this, size_t index);

#endif
